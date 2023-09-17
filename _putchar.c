#include <unistd.h>
#include "main.h"
/**
 * _putchar - writes the _putchar to stdout
 * Return: (1) in success, otherwise -1
 * */


int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
