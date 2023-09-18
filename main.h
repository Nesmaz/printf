#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

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
	char *specifier;
	int (*handler)(va_list);

} specifier_t;



/*Functions */

int _putchar(char ch);
int _printf(const char *format, ...);

int process_format(const char *format,
		specifier_t conversion_specifiers[],
		va_list args);

/*Handlers */

int handle_ch(va_list args);

int handle_str(va_list args);

int handle_percent(va_list args);

int handle_int(va_list args);

int _handle_i(int n);

#endif
