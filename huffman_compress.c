#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "simple_file_utilities.h"
#include "bit_writer.h"
#include "huffman.h"
#include "priority_queue.h"
#include "frequencies.h"
#include "huffman_compress.h"

const char* check_command_line_arguments(int argc, const char* argv[]) {
	if(argc != 3) {
		return ERROR_MSG_USAGE;
	}

	const char* in_path = argv[1];
	const char* out_path = argv[2];

	if(strcmp(in_path, "") == 0) { 
		return ERROR_MSG_INPUT_PATH_BLANK;
	}

	if(!does_path_exist(in_path)) {
		return ERROR_MSG_INPUT_PATH_DOES_NOT_EXIST;
	}

	if(!is_path_a_regular_file(in_path)) {
		return ERROR_MSG_INPUT_PATH_NOT_A_FILE;
	}
	
	FILE* file = fopen(in_path, "r");
	if(file != NULL) {
		fclose(file);
	} else {
		return ERROR_MSG_INPUT_PATH_NOT_READABLE;
	}

	if(strcmp(out_path, "") == 0) { 
		return ERROR_MSG_OUTPUT_PATH_BLANK;
	}

	if(!is_containing_directory_writable(out_path)) {
		return ERROR_MSG_OUTPUT_DIR_NOT_WRITABLE;
	}

	if(does_path_exist(out_path)) {
		return ERROR_MSG_OUTPUT_PATH_EXISTS;
	}


	return NULL; 
}


Metadata compress_file(const char* in_path, const char* out_path) {
	Frequencies freqs = {0};
	char* no_error = "No Errors";
	Metadata header = (Metadata) { .compressed_file_size_bytes = 0, .coding_table_size_bytes = 0, .uncompressed_file_size_bytes = 0 };

	if(calc_frequencies(freqs, in_path, (const char**) &no_error)) {
		FILE* file = fopen(in_path, "r");
		fseek(file, 0, SEEK_END);
		header.uncompressed_file_size_bytes = ftell(file);
		fclose(file);

		TreeNode* tree = make_huffman_tree(make_huffman_pq(freqs));
		BitWriter writer = open_bit_writer(out_path);

		fwrite(&header, sizeof(header), 1, writer.file);

		write_coding_table(tree, &writer);
		flush_bit_writer(&writer);
		header.coding_table_size_bytes = ftell(writer.file) - 12;

		write_compressed(tree, &writer, in_path);
		header.compressed_file_size_bytes = ftell(writer.file) + 1;

		fseek(writer.file, 0, SEEK_SET);
		fwrite(&header, sizeof(header), 1, writer.file);
		fseek(writer.file, 0, SEEK_END);

		close_bit_writer(&writer);
		destroy_huffman_tree(&tree);
	}
	return header;
}


/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
