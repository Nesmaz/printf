#include <stdarg.h>
#include <stddef.h>
#include "main.h"
/**
 * process_format - Processes the format string
 * @format: The format string
 * @conversion_specifiers: Array of conversion specifiers
 * @args: List of arguments
 * Return: The count of characters printed
*/
int process_format(const char *format,
			specifier_t conversion_specifiers[], va_list args)
{
	int i, j, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (is_flag(format[i], "-+ 0#"))
			{
				handle_flag(&format[i],&i);
				i++;
			}
			j = handle_specifiers(format, i, conversion_specifiers, args, &count);
			if (conversion_specifiers[j].specifier == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count += 2;
			} else
				return (-1);
			}
			i++;
		} else
		{
			_putchar(format[i]);
			count++;
		}
	} return (count);
}
