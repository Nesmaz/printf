#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * handle_ptr - Handles the 'p' format specifier
 * @args: variadic list of arguments
 * Return: count of printed characters
*/

int handle_ptr(va_list args)
{
	int j, count = 0;
	void *addr = va_arg(args, void *);
	unsigned long int i = (unsigned long int)addr;
	char buffer[20], *str = &buffer[19];
	*str = '\0';

	if (addr == NULL)
	{
		char *s = "NULL";

		for (j = 0; s[j] != '\0'; j++)
		{
			_putchar(s[j]);
		}
		return (j);
	}

	do {
		*--str = "0123456789abcdef"[i % 16];
		i /= 16;
	} while (i != 0);

	_putchar('0');
	_putchar('x');
	count = 2;
	while (*str)
	{
		_putchar(*str++);
		count++;
	}

	return (count);


}
