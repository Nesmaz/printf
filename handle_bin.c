#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stddef.h>
/**
 * handle_bin - Handler function for the %b format specifier
 * @args: The va_list of arguments
 * Return: count of printed characters
*/
int handle_bin(va_list args)
{
	int n, i, len;
	char *str, *rev;

	n = va_arg(args, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);

	len = l_base(n, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; n > 0; i++)
	{
		if (n % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		n = n / 2;
	}
	str[i] = '\0';
	rev = _rev(str);
	if (rev == NULL)
		return (-1);
	w_base(rev);
	free(str);
	/*free(rev);*/
	return (len);
}

