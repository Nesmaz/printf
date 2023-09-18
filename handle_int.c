#include <stdio.h>
#include "main.h"
/**
 * handle_int - prints integers
 * @args: va_list of arguments
 * Return: count of printed characters
*/
int handle_int(va_list args)
{
	int len;

	len = _handle_i(va_arg(args, int));
	return (len);
}

/**
 * _handle_i - prints integers
 * @n: the number to be printed
 * Return: count of printed characters
*/

int _handle_i(int n)
{
	int len, div;
	unsigned int abs;

	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		abs = n * -1;
	}
	else
	{
	abs = n;
	}

	while (abs / div > 9)
	{
		div *= 10;
	}
	while (div != 0)
	{
		len += _putchar('0' + abs / div);
		abs %= div;
		div /= 10;
	}
	return (len);
}
