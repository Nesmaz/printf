#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * l_base - Calculates the length of a number in a given base
 * @n: The number to calculate the length of
 * @b: The base to use for the calculation
 * Return: The length of the number in the given base
*/

int l_base(unsigned int n, int b)
{
	unsigned int len = 0;

	while (n > 0)
	{
		n /= b;
		len++;
	}

	return (len);
}

/**
 * _rev - Reverses a string
 * @str: string to be reversed
 * Return: pointer to reversed string
*/

char *_rev(char *str)
{
	int i, len = 0;
	char tmp;

	while (str[len] != '\0')
		len++;

	for (i = 0; i < len / 2; i++)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}

	return (str);
}

/**
 * w_base - Writes a string to standard output
 * @out: The string to print
 * Return: count of printed characters
*/

int w_base(char *out)
{
	int count = 0;

	while (*out)
	{
		_putchar(*out);
		count++;
		out++;
	}

	return (count);
}
