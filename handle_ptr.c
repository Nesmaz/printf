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
	int j;
	void *addr = va_arg(args, void *);
	unsigned long int i = (unsigned long int)addr;
	char buffer[20], *str = &buffer[19];
	*str = '\0';

	if (addr == NULL)
	{
		str = "NULL";
		for (j = 0; str[j] != '\0'; j++)
		{
			_putchar(str[j]);
		}
		return (j);
	}

	do {
		*--str = "0123456789abcdef"[i % 16];
		i /= 16;
	} while (i != 0);

	_putchar('0');
	_putchar('x');
	while (*str)
	{
		_putchar(*str++);
	}

	return (str - buffer);


}
