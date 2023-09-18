#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void handle_c(va_list args, int *count);
int _printf(const char *format, ...);
void handle_percent(va_list args, int *count);
void handle_s(va_list args, int *count)
int _putchar(char ch);

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
   /* _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");*/
    return (0);
}
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
			i++;
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
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
void handle_s(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	for (; *s != '\0'; s++)
	{
		_putchar(*s);
		(*count)++;
	}
}
void handle_percent(va_list args, int *count)
{
	(void)args;

	_putchar('%');
	(*count)++;
}
void handle_c(va_list args, int *count)
{
	char c = (char) va_arg(args, int);

	_putchar(c);
	(*count)++;
}
