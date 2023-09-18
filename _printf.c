#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stddef.h>
/**
 * _printf - produces output according to a format
 * @format: the string that specifies the format of the output
 * @...: the variadic arguments to be passed
 * Return: the number of printed characters
 */
int _printf(const char *format, ...)
{
	int i, count;
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
		{NULL, NULL},
	};
	va_list args;
	char buffer[1024];
	int buffer_i = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = process_format(format, conversion_specifiers, args);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (buffer_i == 1024)
			write_buffer(buffer, &buffer_i, &count);
		buffer[buffer_i++] = format[i];
	}

	write_buffer(buffer, &buffer_i, &count);
	va_end(args);
	return (count);
}
