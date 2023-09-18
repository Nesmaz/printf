#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the string that specifies the format of the output
 * @...: the variadic arguments to be passed
 * Return: the number of printed characters
 */

int _printf(const char *format, ...)
{
	int count;
	specifier_t conversion_specifiers[] = {
		{"c", handle_ch},
		{"s", handle_str},
		{"%", handle_percent},
		{"i", handle_int},
		{"d", handle_int},
		{"b", handle_bin},
		{NULL, NULL},
	};
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);
	count = process_format(format, conversion_specifiers, args);
	va_end(args);
	return (count);
}

