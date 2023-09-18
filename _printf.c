#include <stdio.h>
#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formatted string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */

int _printf(const char *format, ...)
{
	int count;
	specifier_t conversion_specifiers[] = {
		{"c", handle_ch},
		{"s", handle_str},
		{"%", handle_percent},
		{NULL, NULL},
	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = process_format(format, conversion_specifiers, args);
	va_end(args);
	return (count);
}

