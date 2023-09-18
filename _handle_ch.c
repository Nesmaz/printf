#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * handle_ch - Handles the %c format specifier
 * @args: A va_list of arguments
 * Return: count of printed characters which is 1
*/

int handle_ch(va_list args)
{
	char c = (char) va_arg(args, int);

	_putchar(c);
	return (1);
}
