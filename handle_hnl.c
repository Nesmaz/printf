#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * handle_short - Handles %h specifier
 * @args: va_list of arguments
 * Return: count of printed characters
*/

int handle_short(va_list args)
{
	short int num = (short)va_arg(args, int);

	return _handle_i(num);
}

/**
 * handle_long - Handles %l specifier
 * @args: va_list of arguments
 * Return: count of printed characters
*/

int handle_long(va_list args)
{
	long int num = va_arg(args, long int);

	return _handle_i(num);
}
