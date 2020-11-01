#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "clog.h"
#include "huffman.h"

static void print_color(char* color) {
	switch(color[0]) {
		case 'r':
			fprintf(stderr, "%s", ANSI_RED);
			break;
		case 'g':
			fprintf(stderr, "%s", ANSI_GREEN);
			break;
		case 'y':
			fprintf(stderr, "%s", ANSI_YELLOW);
			break;
		case 'b':
			fprintf(stderr, "%s", ANSI_BLUE);
			break;
		case 'm':
			fprintf(stderr, "%s", ANSI_MAGENTA);
			break;
		case 'c':
			fprintf(stderr, "%s", ANSI_CYAN);
			break;
		case 'x':
			fprintf(stderr, "%s", ANSI_RESET);
	}
}

int main(int argc, char* argv[]) {
	char g = 'g';
	print_color(&g);
	log_msg("*==========*==========*==========*{ Start Test }*==========*==========*==========*\n");
	
	//
	Node* encoded_tree_topology = topology_reader(argv[1]);
	if(encoded_tree_topology == NULL) {
		return EXIT_FAILURE;
	}

	if(write_nodes(encoded_tree_topology, argv[2]) == 0) {
		return EXIT_FAILURE;
	}

	Tnode* encoded_tree = build_tree_from_topology(&encoded_tree_topology);
	if(encoded_tree == NULL) {
		return EXIT_FAILURE;
	}

	Frequencies freqs = {0};
	long bits = decode_from_tree(argv[1], argv[3], encoded_tree, freqs);
	if(bits == -1) {
		return EXIT_FAILURE;
	}

	if(write_freqs(argv[4], freqs) == 0 ) {
		return EXIT_FAILURE;
	}

	Tnode* huffman_tree = make_huffman_tree(make_huffman_list(freqs));
	if(huffman_tree == NULL) {
		return EXIT_FAILURE;
	}

	Frequencies num_of_bits = {0};
	count_huff_bits(num_of_bits, huffman_tree, 0);

	long huff_bits = add_up_bits(freqs, num_of_bits);

	FILE* fp = fopen(argv[5], "w");
	if(fp == NULL) {
		return EXIT_FAILURE;
	}

	write_tree(fp, huffman_tree);
	fclose(fp);

	if(write_bits(argv[6], bits, huff_bits) == 0) {
		return EXIT_FAILURE;
	}

	destroy_tree(&huffman_tree);
	destroy_tree(&encoded_tree);
	destroy_nodes(encoded_tree_topology);

	log_msg("*==========*==========*==========**{ End Test }**==========*==========*==========*\n\n");
	char x = 'x';
	print_color(&x);
	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
