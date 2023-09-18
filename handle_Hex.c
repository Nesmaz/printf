#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_X - Handler function for the %X format specifier
 * @args: The va_list of arguments
 * Return: count of printed characters
 */
int handle_X(va_list args)
{
	unsigned int num;
	int len;
	char *HEX, *rev_HEX;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	len = l_base(num, 16);
	HEX = malloc(sizeof(char) * len + 1);

	if (HEX == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		if ((num % 16) < 10)
			HEX[len] = (num % 16) + '0';
		else
			HEX[len] = (num % 16) - 10 + 'A';
		num /= 16;
	}

	HEX[len] = '\0';
	rev_HEX = _rev(HEX);
	if (rev_HEX == NULL)
		return (-1);

	w_base(rev_HEX);
	free(HEX);

	return (len);
}
