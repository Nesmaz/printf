#include <stdio.h>
#include "main.h"
#include <stddef.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 * @format: the string that specifies the format of the output
 * @...: the variadic arguments to be passed
 * Return: the number of printed characters
*/
int _printf(const char *format, ...)
{
	int i, count = 0;
	size_t j;
	va_list args;

	specifier_t specifiers[] = {
		{'c', handle_c},
		{'s', handle_s},
		{'%', handle_percent},
	};
	va_start(args, format);
	if (format == NULL)
		return (-1);
	if (format[0] == '%' && !format[1])
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			++i;
			for (j = 0; j < sizeof(specifiers) / sizeof(specifier_t); j++)
			{
				if (format[i] == specifiers[j].specifier)
				{
					specifiers[j].handler(args, &count);
					break;
				}
			}
			if (j == sizeof(specifiers) / sizeof(specifier_t))
				return (-1);
		}
	}
	va_end(args);
	return (count);
}
