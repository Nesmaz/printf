#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * struct specifier_t - Format specifier
 * @specifier: The format specifier character
 * @handler: The function to handle the format specifier
 *
 * description: a struct that maps a format specifier character to
 *		a corresponding handler function.
 *		Each instance of this struct represents one format specifier-handler pair.
*/

typedef struct specifier_t
{
	char specifier;
	void (*handler)(va_list args, int *count);
} specifier_t;

/*Functions */

int _putchar(char ch);

int _printf(const char *format, ...);

/*Handlers */

void handle_c(va_list args, int *count);

void handle_s(va_list args, int *count);

void handle_percent(va_list args, int *count);

#endif
