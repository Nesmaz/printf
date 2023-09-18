#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_percent - handles the %% format specifier
 * @args:  va_list of arguments
 * Return: count of printed characters which is one
*/

int handle_percent(va_list args)
{
	(void)args;

	_putchar('%');
	return (1);
}
