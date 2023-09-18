#include <stdio.h>
#include "main.h"
/**
 * _putchar - writes the character to stdout
 * @ch: The character to print
 * Return: (1) on success, otherwise -1
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
