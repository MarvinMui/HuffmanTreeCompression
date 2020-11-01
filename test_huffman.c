#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "huffman.h"
#include "miniunit.h"

/*
static void _help_me_freq(Frequencies freqs) {
	printf("  ");
	for(int i = 0; i < 25; i++) {
		printf("%3d", i + 1);
	}
	
	printf("\n  ");
	for(int i = 0; i < 75; i++) {
		printf("=");
	}
	
	for(int i = 0; i < 256; i++) {
		if(i % 25 == 0) {
			printf("\n%2d", i / 25 + 1);
		}
		printf("%3d",(int) freqs[i]);
	}
	printf("\n");
}


static bool _is_correct(Node* head) {
	int i = ((TreeNode*)(head -> a_value)) -> frequency;
	for(Node* curr = head; curr != NULL; curr = curr -> next) {
		if(i > (((TreeNode*)(curr -> a_value)) -> frequency)) {
			return false;
		}
		i = ((TreeNode*)(curr -> a_value)) -> frequency;
	}
	return true;
}


static void _delete_struct(void* tree) {
	free(tree);
}


static void _help_me_order(Node* head) {
	for(Node* curr = head; curr != NULL; curr = curr -> next) {
		printf("char: %c, freq: %ld\n", (char)(((TreeNode*)(curr -> a_value)) -> character), (((TreeNode*)(curr -> a_value)) -> frequency));
	}
}


static void _print_tree(TreeNode* tree) {
	if(tree -> left != NULL) {
		_print_tree(tree -> left);
	}

	if(tree -> right != NULL) {
		_print_tree(tree -> right);
	}
	
	if(tree -> character == '\0') {
		printf("Cluster Root\n");

	} else if(tree -> character == '\n') {
		printf("New Line\n");

	} else {
		printf("%c\n", tree -> character);
	}

	
}
*/

int _test_dio() {
	mu_start();
	//────────────────────
	Frequencies freqs = {0};
	const char* path = "saint_motel.txt";
	char* no_error = "No Errors";

	mu_check(calc_frequencies(freqs, path, (const char**) &no_error));
	TreeNode* bed = make_huffman_tree(make_huffman_pq(freqs));
	BitWriter murakami = open_bit_writer("lalas.txt");
	write_coding_table(bed, &murakami);
	
	close_bit_writer(&murakami);
	destroy_huffman_tree(&bed);
	//────────────────────
	mu_end();
}


int _test_jojo() {
	mu_start();
	//────────────────────
	Frequencies freqs = {0};
	const char* path = "arthur.c";
	char* no_error = "No Errors";
	FILE* yop = fopen(path, "w");
	//uint8_t huff[] = "she sells seashells by the seashore";
	uint8_t huff[] = "huffman fluffs many mums";
	fwrite(huff, sizeof(char), 24, yop);
	fclose(yop);
	
	mu_check(calc_frequencies(freqs, path, (const char**) &no_error));
	TreeNode* bed = make_huffman_tree(make_huffman_pq(freqs));
	BitWriter kafka = open_bit_writer("songs.txt");
	//write_coding_table(bed, &kafka);

	uint8_t shuff[] = "huffman fluffs many mums";
	write_compressed(bed, &kafka, shuff);

	close_bit_writer(&kafka);
	destroy_huffman_tree(&bed);
	//────────────────────
	mu_end();
}


int _test_caesar() {
	mu_start();
	//────────────────────
	Frequencies freqs = {0};
	const char* path = "willow.txt";
	char* no_error = "No Errors";

	mu_check(calc_frequencies(freqs, path, (const char**) &no_error));
	TreeNode* bed = make_huffman_tree(make_huffman_pq(freqs));
	BitWriter kafka = open_bit_writer("waawaa.txt");
	write_coding_table(bed, &kafka);
	
	close_bit_writer(&kafka);
	destroy_huffman_tree(&bed);
	//────────────────────
	mu_end();
}


int main(int argc, char* argv[]) {
	mu_run(_test_dio);
	mu_run(_test_jojo);
	mu_run(_test_caesar);
	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
