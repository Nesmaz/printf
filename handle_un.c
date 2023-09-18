#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_un - Handler function for the %u format specifier
 * @args: va_list of arguments
 * Return: count of printed characters
*/

int handle_un(va_list args)
{
	unsigned int n;
	int len;
	char *num_rep, *rev_num;

	n = va_arg(args, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
	{
		return (-1);
	}

	len = l_base(n, 10);
	num_rep = malloc(sizeof(char) * len + 1);

	if (num_rep == NULL)
		return (-1);

	for (len = 0; n > 0; len++)
	{
		num_rep[len] = (n % 10) + '0';
		n /= 10;
	}

	num_rep[len] = '\0';
	rev_num = _rev(num_rep);
	if (rev_num == NULL)
		return (-1);

	w_base(rev_num);
	free(num_rep);

	return (len);

}
