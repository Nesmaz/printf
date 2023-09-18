#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_s - handles the %s format specifier
 * @args: va_list of arguments
 * Return: the length of the string
*/

int handle_str(va_list args)
{
	char *s = "";
	int j, count = 0;

	s = va_arg(args, char *);

	for (j = 0; s[j] != '\0'; j++)
	{
		_putchar(s[j]);
		count++;
	}
	return (count);
}
