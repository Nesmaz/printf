#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * to_hex - Converts a number to a hexadecimal character
 * @n: The number to convert
 * Return: The hexadecimal representation
 *	of the number as a character
*/
char to_hex(int n)
{
	return (n < 10 ? ('0' + n) : ('A' + n - 10));
}

/**
 * handle_S - handles the %S format specifier
 * @args: va_list of arguments
 * Return: count of printed characters
 *
 * Description: This function prints a string, but with special handling for
 * non-printable characters
*/

int handle_S(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;

	if (!str)
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar(to_hex(str[i] / 16));
			_putchar(to_hex(str[i] % 16));
			count += 4;
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
