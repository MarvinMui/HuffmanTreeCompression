#ifndef __CLOG_H__
#define __CLOG_H__

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

#ifdef DEBUG
#	define log_msg(msg) fprintf(stderr, "%s", (msg))
#	define log_int(n) fprintf(stderr, "%s == ", (#n)); \
							log_cyan("%d\n", (n))
#	define log_str(s) fprintf(stderr, "%s == %s\n", (#s), (uchar) (s))
#	define log_char(c) fprintf(stderr, "%s == '%c'\n", (#c), (c))
#	define log_addr(addr) fprintf(stderr, "%s == ", (#addr)); \
							log_magenta("%p\n", (addr))
#	define log_red(...) __mu_log_color(ANSI_RED, __VA_ARGS__)
#	define log_green(...) __mu_log_color(ANSI_GREEN, __VA_ARGS__)
#	define log_yellow(...) __mu_log_color(ANSI_YELLOW, __VA_ARGS__)
#	define log_blue(...) __mu_log_color(ANSI_BLUE, __VA_ARGS__)
#	define log_magenta(...) __mu_log_color(ANSI_MAGENTA, __VA_ARGS__)
#	define log_cyan(...) __mu_log_color(ANSI_CYAN, __VA_ARGS__)
#else
#	define log_msg(msg)
#	define log_int(n)
#	define log_str(s)
#	define log_char(c)
#	define log_addr(addr)
#	define log_red(...)
#	define log_green(...)
#	define log_yellow(...)
#	define log_blue(...)
#	define log_magenta(...)
#	define log_cyan(...)
#endif

#define __mu_log_color(color, ...) do { \
	if(isatty(STDERR_FILENO)) { \
		fprintf(stderr, "%s", color); \
	} \
	fprintf(stderr, __VA_ARGS__); \
	if(isatty(STDERR_FILENO)) { \
		fprintf(stderr, "%s", ANSI_RESET); \
	} \
} while(false)

#endif
