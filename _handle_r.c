#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_r - handles the %r speical format specifier
 * @args: va_list of arguments
 * Return: the length of the string
*/

int handle_r(va_list args)
{
	char *s = va_arg(args, char *);
	int j, count = 0;

	for (j = 0; s[j] != '\0'; j++)
	{
/*		_putchar(s[j]);*/
		count++;
	}
	for (j = 0; j < count; j++)
	{
		int n = count - j - 1;

		_putchar(s[n]);
	}
	return (count);
}
