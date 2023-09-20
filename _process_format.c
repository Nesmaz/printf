#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"
/**
 * process_format - Processes the format string
 * @format: The format string
 * @conversion_specifiers: Array of conversion specifiers
 * @args: List of arguments
 *
 * This function processes a format string.
 * It iterates over each character in the string.
 * If it encounters a '%', it checks the next character
 * against the list of conversion specifiers.
 * If it finds a match, it calls the corresponding handler function
 * and adds its return value to the count.
 * If it doesn't find a match and the next character is not a space,
 * it prints the '%' and the next character.
 * If the next character is a null byte, it returns -1.
 * For all other characters, it prints them as they are.
 *
 * Return: The count of characters printed
*/
int process_format(const char *format,
		specifier_t conversion_specifiers[],
		va_list args)
{
	int i, j, handler_return, count = 0;

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
