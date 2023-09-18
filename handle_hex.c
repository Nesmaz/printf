#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_x - Handler function for the %x format specifier
 * @args: va_list of arguments
 * Return: count of printed characters
*/
int handle_x(va_list args)
{
	unsigned int num;
	int len;
	char *hex, *rev_hex;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	len = l_base(num, 16);
	hex = malloc(sizeof(char) * len + 1);

	if (hex == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		if ((num % 16) < 10)
			hex[len] = (num % 16) + '0';
		else
			hex[len] = (num % 16) - 10 + 'a';
		num /= 16;
	}

	hex[len] = '\0';
	rev_hex = _rev(hex);
	if (rev_hex == NULL)
		return (-1);

	w_base(rev_hex);
	free(hex);

	return (len);
}

