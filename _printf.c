#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stddef.h>

#define BUFFER_SIZE 1024
/**
 * _printf - produces output according to a format
 * @format: the string that specifies the format of the output
 * Return: the number of printed characters
 */
int _printf(const char *format, ...)
{
	int count = 0;

	specifier_t conversion_specifiers[] = {
		{"c", handle_ch},
		{"s", handle_str},
		{"%", handle_percent},
		{"i", handle_int},
		{"d", handle_int},
		{"b", handle_bin},
		{"o", handle_oct},
		{"u", handle_un},
		{"x", handle_x},
		{"X", handle_X},
		{"S", handle_S},
		{"p", handle_ptr},
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
