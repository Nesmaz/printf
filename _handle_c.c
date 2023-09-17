#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * handle_c - Handles the %c format specifier
 * @args: A va_list of arguments
 * @count: A pointer to the count of characters printed so far
*/

void handle_c(va_list args, int *count)
{
	char c = (char) va_arg(args, int);

	_putchar(c);
	(*count)++;
}
