#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_oct - Handler function for the %o format specifier
 * @args: va_list of arguments
 * Return: count of printed characters
*/

int handle_oct(va_list args)
{
	unsigned int n;
	int len;
	char *octal, *rev;

	n = va_arg(args, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);

	len = l_base(n, 8);

	octal = malloc(sizeof(char) * len + 1);

	if (octal == NULL)
		return (-1);

	for (len = 0; n > 0; len++)
	{
		octal[len] = (n % 8) + '0';
		n /= 8;
	}

	octal[len] = '\0';
	rev = _rev(octal);

	if (rev == NULL)
		return (-1);
	w_base(rev);
	free(octal);
	return (len);

}
