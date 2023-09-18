#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

int process_format(const char *format, specifier_t conversion_specifiers[], va_list args)
{
	int i, j, handler_return, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; conversion_specifiers[j].specifier != NULL; j++)
			{
				if (format[i + 1] == conversion_specifiers[j].specifier[0])
				{
					handler_return = conversion_specifiers[j].handler(args);
					if (handler_return == -1)
						return (-1);
					count += handler_return;
					break;
				}
			}
			if (conversion_specifiers[j].specifier == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count += 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	return (count);
}

