#include <stdio.h>
#include "main.h"
/**
 * is_flag - Checks if a character is a flag
 * @c: The character to check
 * This function checks if a character is one of the flag characters
 * used in format strings ('-', '+', '0', '#', ' '). It returns 1 if
 * the character is a flag, and 0 otherwise.
 * Return: 1 if the character is a flag, 0 otherwise
 */
int is_flag(char c, const char *flags)
{
	int i;

	for (i = 0; flags[i] != '\0'; i++)
	{
		if (c == flags[i])
			return (1);
	}
	return (0);
}
/**
 * handle_specifiers - Handles the conversion specifiers
 * @format: The format string
 * @i: The current position in the format string
 * @conversion_specifiers: Array of conversion specifiers
 * @args: List of arguments
 * @count: A pointer to the count of characters printed
 * Return: The index of the specifier that was handled,
 *	or -1 if no specifier was handled
*/
int handle_specifiers(const char *format, int i,
		specifier_t conversion_specifiers[], va_list args, int *count)
{
	int j, handler_return;

	for (j = 0; conversion_specifiers[j].specifier != NULL; j++)
	{
		if (format[i + 1] == conversion_specifiers[j].specifier[0])
		{
			handler_return = conversion_specifiers[j].handler(args);
			if (handler_return == -1)
				return (-1);
			*count += handler_return;
			return (j + 1);
		}
	} return (-1);
}
