#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "frequencies.h"
#include <string.h>

bool calc_frequencies(Frequencies freqs, const char* path, const char** a_error) {
	FILE* fp = fopen(path, "r");
	if(fp != NULL) {
		for(char ch = fgetc(fp); !feof(fp); ch = fgetc(fp)) {
			freqs[(uchar) ch] += 1;
		}
		fclose(fp);
		return true;

	} else {
		*a_error = strerror(errno);
		return false;
	}
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
