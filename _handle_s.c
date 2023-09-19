#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_str - handles the %s format specifier
 * @args: va_list of arguments
 * Return: the length of the string
*/

int handle_str(va_list args)
{
	char *s = va_arg(args, char *);
	int j, count = 0;

	for (j = 0; s[j] != '\0'; j++)
	{
		_putchar(s[j]);
		count++;
	}
	return (count);
}
