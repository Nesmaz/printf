#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_percent - handles the %% format specifier
 * @args:  va_list of arguments
 * @count: pointer to the count of characters printed so far
*/

void handle_percent(va_list args, int *count)
{
	(void)args;

	_putchar('%');
	(*count)++;
}
