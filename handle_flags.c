/**
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * handle_flag - Parses the format string and identifies which flags are set
 * @format: The format string to parse
 * @i: A pointer to the current position in the format string
 * Return: An integer where each bit represents a different flag
*/
/**
int handle_flag(const char *format, int *i)
{
	int flags = 0;

	while (is_flag(*i, "-+ 0#"))
	{
		switch (format[*i])
		{
			case '-':
				{
					flags |= 1;
					break;
				}
			case '+':
				{
					flags |= 2;
					break;
				}
			case '0':
				{
					flags |= 4;
					break;
				}
			case '#':
				{
					flags |= 8;
					break;
				}
			case ' ':
				{
					flags |= 16;
					break;
				}
			default:
				{
					return (flags);
				}
		}
		(*i)++;
	}
	return (flags);
}
*/
