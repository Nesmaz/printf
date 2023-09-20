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
		specifier_t conversion_specifiers[],
		va_list args)
{
	int i, j, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; conversion_specifiers[j].specifier != NULL; j++)
			{
				if (format[i] ==  conversion_specifiers[j].specifier[0])
				{
					count +=  conversion_specifiers[j].handler(args);
					break;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	return (count);
}
