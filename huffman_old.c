#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "frequencies.h"
#include "priority_queue.h"
#include "huffman.h"
#include "bit_writer.h"


static int _freq_comp(const void* head, const void* new) {
	if((((const TreeNode*)head) -> frequency) == (((const TreeNode*)new) -> frequency)) {
		if((((const TreeNode*)head) -> character) == '\0') {
			return 1;
		} else if((((const TreeNode*)new) -> character) == '\0') { 
			return -1;
		} else {
			return ((const TreeNode*)head) -> character - ((const TreeNode*)new) -> character;
		}
	}

	return (((const TreeNode*)head) -> frequency) - (((const TreeNode*)new) -> frequency);
}


Node* make_huffman_pq(Frequencies freqs) {
	Node* head = NULL;
	for(int i = 255; i >= 0; i--) {
		if(freqs[i] != 0) {
			TreeNode* new_tree = malloc(sizeof(*new_tree));
			*new_tree = (TreeNode) { .character = i, .frequency = freqs[i], .left = NULL, .right = NULL };
			pq_enqueue(&head, new_tree, _freq_comp);
		}
	}
	return head;
}


void destroy_huffman_tree(TreeNode** a_root) {
	if(*a_root != NULL) {
		if((*a_root) -> right != NULL) {
			destroy_huffman_tree(&((*a_root) -> right));
		}

		if((*a_root) -> left != NULL) {
			destroy_huffman_tree(&((*a_root) -> left));
		}

		free(*a_root);
		*a_root = NULL;
	}
}


TreeNode* make_huffman_tree(Node* head) {
	Node* curr = head;
	if(curr == NULL) {
		return NULL;
	}
	while(curr -> next != NULL) {
		TreeNode* new_tree = malloc(sizeof(*new_tree));

		size_t new_size = (((TreeNode*)(curr -> a_value)) -> frequency + ((TreeNode*)(curr -> next -> a_value)) -> frequency);
		TreeNode* left = ((TreeNode*)(curr -> a_value));
		TreeNode* right = ((TreeNode*)(curr -> next -> a_value));
		*new_tree = (TreeNode) { .character = '\0', .frequency = new_size, .left = left, .right =  right};

		pq_enqueue(&curr, new_tree, _freq_comp);
		curr = curr -> next -> next;
		free(pq_dequeue(&head));
		free(pq_dequeue(&head));
	}
	TreeNode* tree = ((TreeNode*) (curr -> a_value));
	free(head);

	return tree;
}


void write_coding_table(TreeNode* root, BitWriter* a_writer) {
	if(root != NULL) {
		if(root -> left != NULL) {
			write_coding_table(root -> left, a_writer);
		}

		if(root -> right != NULL) {
			write_coding_table(root -> right, a_writer);
		}

		if(root -> character == '\0') {
			write_bits(a_writer, 0, 1); 
		} else {
			write_bits(a_writer, 1, 1);
			write_bits(a_writer, root -> character, 8);
		}
	}
}


static void _fill_lookup(Code* a_uncompressed, TreeNode* a_root, uint8_t hex, uint8_t level) {
	if(a_root != NULL) {
		if(a_root -> left != NULL) {
			_fill_lookup(a_uncompressed, a_root -> left, hex << 1, ++level);
			level--;
		}

		if(a_root -> right != NULL) {
			_fill_lookup(a_uncompressed, a_root -> right, (hex << 1) + 1, ++level);
			level--;
		}

		if(a_root -> character != '\0') {
			a_uncompressed[a_root -> character] = (Code) { .bits = hex, .num_bits = level }; 
		}
	}
}


void write_compressed(TreeNode* root, BitWriter* a_writer, const char* in_path) {
	Code uncompressed[256];
	for(int code_idx = 0; code_idx < 256; code_idx++) {
		uncompressed[code_idx] = (Code) { .bits = 0, .num_bits = 0 };
	}

	_fill_lookup(uncompressed, root, 0, 0);
	FILE* file = fopen(in_path, "r"); 

	for(uint8_t ch = fgetc(file); !feof(file); ch = fgetc(file)) {
		write_bits(a_writer, uncompressed[ch].bits, uncompressed[ch].num_bits);
	}

	fclose(file);
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
