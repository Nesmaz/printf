#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * struct specifier_t - Format specifier
 * @specifier: The format specifier character
 * @handler: The function pointer to the handler
 *
 * description: a struct that maps a format specifier character to
 *		a corresponding handler function.
 *		Each instance of this struct represents one format specifier-handler pair.
*/

typedef struct specifier_t
{
	const char *specifier;
	int (*handler)(va_list);

} specifier_t;



/*Functions */

int _putchar(char ch);
int _printf(const char *format, ...);

int process_format(const char *format,
		specifier_t conversion_specifiers[],
		va_list args);

int _handle_i(int n);

int _handle_bin(unsigned int n);

int l_base(unsigned int n, int b);

char *_rev(char *str);

int w_base(char *out);

char to_hex(int n);

int handle_flag(const char *format, int *i);

int is_flag(char c, const char *flags);

int handle_specifiers(const char *format, int i,
		specifier_t conversion_specifiers[],
		va_list args, int *count);

/*Handlers */

int handle_ch(va_list args);

int handle_str(va_list args);

int handle_percent(va_list args);

int handle_int(va_list args);

int handle_bin(va_list args);

int handle_oct(va_list args);

int handle_un(va_list args);

int handle_x(va_list args);

int handle_X(va_list args);

int handle_S(va_list args);

int handle_ptr(va_list args);

int handle_r(va_list args);

#endif
