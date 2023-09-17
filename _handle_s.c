#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_s - handles the %s format specifier
 * @args: va_list of arguments
 * @count: pointer to the count of characters printed so far
*/

void handle_s(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	for (; *s != '\0'; s++)
	{
		_putchar(*s);
		(*count)++;
	}
}
