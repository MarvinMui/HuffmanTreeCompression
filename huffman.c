#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "huffman.h"
#include "clog.h"

Node* add_node(Node* tail, char value) {

	Node* temp = malloc(sizeof(*temp));
	if(temp == NULL) {
		return NULL;
	}
	*temp = (Node) { .value = value, .next = NULL };

	tail -> next = temp;
	tail = temp;
	return tail;
}

void destroy_nodes(Node* head) {
	if(head != NULL) {
		while(head -> next != NULL) {
			Node* deletor = head;
			head = head -> next;
			free(deletor);
		}
		free(head);
	}
}

void destroy_tree(Tnode** root) {
	if((*root) != NULL) {
		destroy_tree(&((*root) -> left));
		destroy_tree(&((*root) -> right));
		free(*root);
		*root = NULL;
	}
}

Node* topology_reader(char* filename) {
	// 				Open file
	FILE* fp = fopen(filename, "r");
	if(fp != NULL) {
		// 			Get topology length
		fseek(fp, sizeof(long), SEEK_SET);
		long* top_length = malloc(sizeof(long));
		if(top_length == NULL) {
			fclose(fp);
			return NULL;
		}
		fread(top_length, sizeof(long), 1, fp);

		// 			Begin reading bytes
		fseek(fp, sizeof(long), SEEK_CUR);
		Node* dummy = malloc(sizeof(*dummy));
		if(dummy == NULL) {
			free(top_length);
			fclose(fp);
			return NULL;
		}

		*dummy = (Node) { .value = '0', .next = NULL };
		Node* tail = dummy;
		if(*top_length == 0) {
			free(top_length);
			fclose(fp);
			return dummy;
		}

		for(int i = 0; i < *top_length; i++) {
			// 		Read one byte
			uint8_t read_byte;
			fread(&read_byte, sizeof(read_byte), 1, fp);

			for(int j = 0; j < 8; j++) {
				// 	Select least significant bit
				uint8_t cur_bit = read_byte & 0x1;

				// 	Add bit
				tail = add_node(tail, cur_bit + '0');	
				if(tail == NULL) {
					destroy_nodes(dummy);
					free(top_length);
					fclose(fp);
					return NULL;
				}

				read_byte = read_byte >> 1;

				// 	Add char, if needed
				if(cur_bit == 1) {
					cur_bit = read_byte;
					fread(&read_byte, sizeof(read_byte), 1, fp);
					cur_bit |= (read_byte << (8 - j - 1));
					i++;

					tail = add_node(tail, cur_bit);
					if(tail == NULL) {
						destroy_nodes(dummy);
						free(top_length);
						fclose(fp);
						return NULL;
					}

					read_byte = read_byte >> (j + 1);

					if(i == *top_length - 1) {
						j = 8;
					}
				}
			}
		}

		fclose(fp);
		free(top_length);
		tail = dummy -> next;
		free(dummy);
		return tail;
	}
	return NULL;
}

int write_nodes(Node* head, char* filename) {
	FILE* fp = fopen(filename, "w");
	if(fp != NULL) {
		if(head -> next == NULL) {
			fclose(fp);
			return 1;
		}
		while(head != NULL) {
			fwrite(&(head -> value), sizeof((head -> value)), 1, fp); 
			head = head -> next;
		}
		fclose(fp);
		return 1;
	}
	return 0;
}

Tnode* build_tree_from_topology(Node** head) {
	if((*head) != NULL) {
		Tnode* root = malloc(sizeof(*root));
		if(root == NULL) {
			return NULL;
		}
		if((*head) -> value == '0') {
			*root = (Tnode) { .value = -1, .frequency = 0, .left = NULL, .right = NULL };
			*head = (*head) -> next;
			root -> left = build_tree_from_topology(head);
			root -> right = build_tree_from_topology(head);
		} else {
			*root = (Tnode) { .value = (*head) -> next -> value, .frequency = 0, .left = NULL, .right = NULL };
			*head = (*head) -> next -> next;
		}
		return root;
	}
	return NULL;
}

long decode_from_tree(char* read_file, char* write_file, Tnode* root, Frequencies freqs) {
	long bits = 0;
	// 									Open Files
	FILE* fpr = fopen(read_file, "r");
	if(fpr != NULL) {

		// 							Get Topology Length
		fseek(fpr, sizeof(long), SEEK_SET);
		long* top_length = malloc(sizeof(long));
		if(top_length == NULL) {
			fclose(fpr);
			return -1;
		}
		fread(top_length, sizeof(long), 1, fpr);					

		// 							Get Uncompressed File Length
		long* tot_bytes = malloc(sizeof(long));
		if(tot_bytes == NULL) {
			free(top_length);
			fclose(fpr);
			return -1;
		}
		fread(tot_bytes, sizeof(long), 1, fpr);

		if(*tot_bytes == 0) {
			free(tot_bytes);
			free(top_length);
			fclose(fpr);
			return 0;
		}


		fseek(fpr, *top_length, SEEK_CUR);
		int cur_byte = 0;
		Tnode* temp = root;

		FILE* fpw = fopen(write_file, "w");
		if(fpw != NULL) {
			//							Start Reading
			while(!feof(fpr)) {
				uint8_t read_byte;
				fread(&read_byte, sizeof(read_byte), 1, fpr);

				for(int j = 0; j < 8 && cur_byte < *tot_bytes; j++) {
					//					Select least significant bit
					uint8_t cur_bit = read_byte & 0x1; 						

					if(temp != NULL) {
						if(cur_bit == 0 && temp -> left != NULL) {
							temp = temp -> left;
						} else if(temp -> right != NULL) {
							temp = temp -> right;
						}

						//				If leaf node, write to file
						if(temp != NULL && temp -> value != -1 && temp -> left == NULL && temp -> right == NULL) {
							fwrite(&(temp -> value), sizeof(char), 1, fpw);
							freqs[temp -> value] += 1;
							temp = root;
							cur_byte++;
						}
					}
					read_byte = read_byte >> 1;
					bits++;
				}
			}

			free(tot_bytes);
			free(top_length);
			fclose(fpw);
		}

		fclose(fpr);
	}
	return bits;
}

int write_freqs(char* filename, Frequencies freqs) {
	FILE* fp = fopen(filename, "w");
	if(fp != NULL) {
		for(int i = 0; i < 256; i++) {
			fwrite(&(freqs[i]), sizeof(long), 1, fp);
		}
		fclose(fp);
		return 1;
	}
	return 0;
}

void add_node_in_order(NodeL** a_head, void* a_value, int (*comp_funct)(const void*, const void*)) {
	NodeL* new_node = malloc(sizeof(*new_node));
	*new_node = (NodeL) { .a_value = a_value, .next = *a_head };

	if(*a_head == NULL || comp_funct(new_node -> a_value, (*a_head) -> a_value) <= 0) {
		*a_head = new_node;
	} else {
		new_node -> next = (*a_head) -> next;
		(*a_head) -> next = new_node;
		NodeL* curr = *a_head;

		while(new_node -> next != NULL && comp_funct(new_node -> next -> a_value, new_node -> a_value) <= 0) {
			curr -> next = new_node -> next;
			curr = curr -> next;
			new_node -> next = curr -> next;
			curr -> next = new_node;
		}
	}
}

int tree_comp_func(const void* head, const void* new) {
	if((((const Tnode*)head) -> frequency) == (((const Tnode*) new) -> frequency)) {

		if(((const Tnode*)head) -> value == -1) {
			return 1;
		} else if(((const Tnode*)new) -> value == -1) {
			return -1;
		} else {
			return (((const Tnode*)head) -> value) - (((const Tnode*) new) -> value);
		}

	}
	return (((const Tnode*)head) -> frequency) - (((const Tnode*) new) -> frequency);
}

NodeL* make_huffman_list(Frequencies freqs) {
	NodeL* head = NULL;
	for(int i = 0; i < 256; i++) {
		if(freqs[i] != 0) {
			Tnode* new_tree = malloc(sizeof(*new_tree));
			*new_tree = (Tnode) { .value = i, .frequency = freqs[i], .left = NULL, .right = NULL };
			add_node_in_order(&head, new_tree, tree_comp_func);
		}
	}
	return head;
}

NodeL* pop(NodeL** a_head) {
	NodeL* save = *a_head;
	if(*a_head != NULL) {
		*a_head = (*a_head) -> next;
		save -> next = NULL;
	}
	return save;
}

Tnode* make_huffman_tree(NodeL* head) {
	NodeL* curr = head;
	if(curr == NULL) {
		Tnode* empty = malloc(sizeof(*empty));
		*empty = (Tnode) { .value = -1, .frequency = 0, .left = NULL, .right = NULL };
		return empty;
	}

	while(curr -> next != NULL) {
		Tnode* new_tree = malloc(sizeof(*new_tree));

		long new_size = ((Tnode*)(curr -> a_value)) -> frequency + 
			((Tnode*)(curr -> next -> a_value)) -> frequency;
		Tnode* left = ((Tnode*)(curr -> a_value));
		Tnode* right = ((Tnode*)(curr -> next -> a_value));

		*new_tree = (Tnode) { .value = -1, .frequency = new_size, .left = left, .right = right };

		add_node_in_order(&curr, new_tree, tree_comp_func);
		curr = curr -> next -> next;
		free(pop(&head));
		free(pop(&head));
	}

	Tnode* tree = ((Tnode*)(curr -> a_value));
	free(head);

	return tree;
}

void write_tree(FILE* fp, Tnode* root) {
	if(root != NULL) {
		if(root -> value == 255) {
			char zero = '0';
			fwrite(&zero, sizeof(char), 1, fp);
		} else {
			char one = '1';
			fwrite(&one, sizeof(char), 1, fp);
			fwrite(&(root -> value), sizeof(char), 1, fp);
		}
		if(root -> left != NULL) {
			write_tree(fp, root -> left);
		}
		if(root -> right != NULL) {
			write_tree(fp, root -> right);
		}
	}	
}

void count_huff_bits(Frequencies freqs, Tnode* root, long stack) {
	if(root != NULL) {
		if(root -> value != -1) {
			freqs[root -> value] += stack;	
		}
		stack++;
		if(root -> left != NULL) {
			count_huff_bits(freqs, root -> left, stack);
		}
		if(root -> right != NULL) {
			count_huff_bits(freqs, root -> right, stack);
		}
	}
}

int write_bits(char* filename, long bits, long huff_bits) {
	FILE* fp = fopen(filename, "w");
	if(fp != NULL) {
		long bytes = bits / 8;
		int leftover_bits = bits % 8;
		fwrite(&bytes, sizeof(long), 1, fp);
		fwrite(&leftover_bits, sizeof(int), 1, fp);

		long huff_bytes = huff_bits / 8;
		int leftover_huff_bits = huff_bits % 8;
		fwrite(&huff_bytes, sizeof(long), 1, fp);
		fwrite(&leftover_huff_bits, sizeof(int), 1, fp);
		fclose(fp);
		return 1;
	}
	return 0;
}

long add_up_bits(Frequencies freqs, Frequencies num_of_bits) {
	long huff_bits = 0;
	for(int i = 0; i < 256; i++) {
		huff_bits += freqs[i] * num_of_bits[i];
	}
	return huff_bits;
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
