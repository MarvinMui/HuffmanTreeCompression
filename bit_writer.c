#include <assert.h>
#include "bit_writer.h"

BitWriter open_bit_writer(const char* path) {
	return (BitWriter) { .file = fopen(path, "w"), .current_byte = 0, .num_bits_left = 8 };
}

void write_bits(BitWriter* a_writer, uint8_t bits, uint8_t num_bits_to_write) {
	assert((0 <= num_bits_to_write) && (num_bits_to_write <= 8));
	assert((1 <= a_writer -> num_bits_left) & (a_writer -> num_bits_left <= 8));
	
	if(num_bits_to_write > a_writer -> num_bits_left) {
		num_bits_to_write -= a_writer -> num_bits_left;
		write_bits(a_writer, bits >> num_bits_to_write, a_writer -> num_bits_left);
	}
	
	a_writer -> current_byte |= (bits << (a_writer -> num_bits_left - num_bits_to_write)) & (0xff >> (8 - a_writer -> num_bits_left));
	
	if(a_writer -> num_bits_left - num_bits_to_write == 0) {
		fwrite(&(a_writer -> current_byte), sizeof(a_writer -> current_byte), 1, a_writer -> file);
		a_writer -> current_byte = 0;
		a_writer -> num_bits_left = 8 + num_bits_to_write;
	}

	a_writer -> num_bits_left -= num_bits_to_write;

	assert((1 <= num_bits_to_write) && (num_bits_to_write <= 8));
}

void flush_bit_writer(BitWriter* a_writer) {
	write_bits(a_writer, a_writer -> current_byte, a_writer -> num_bits_left);
	fflush(a_writer -> file);
}

void close_bit_writer(BitWriter* a_writer) {
	flush_bit_writer(a_writer);
	fclose(a_writer -> file);
	a_writer -> file = NULL;
}

#define __BIT_WRITER_C_V1__
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab colorcolumn=96: */
