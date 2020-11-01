#include <stdbool.h>
#include "clog.h"

#define mu_start() int __mu_var = 0 
#define mu_check(condition) if(!(condition) && __mu_var == 0) __mu_var = __LINE__
#define mu_check_strings_eq(s1, s2)  mu_check(strcmp((s1), (s2)) == 0)
#define mu_run(function) \
	do { \
		int __mu_n = function(); \
		if(__mu_n == 0) { \
   		fprintf(stderr, ANSI_GREEN "Test Passed: %s\n" ANSI_RESET, (#function)); \
		} else { \
			fprintf(stderr, ANSI_RED "Test Failed: %s on line %d\n" ANSI_RESET, (#function), (__mu_n)); \
		} \
	} while(false)
#define mu_end() return __mu_var
