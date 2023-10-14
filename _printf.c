#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * char_conversion - deals with %c specifier
 * @arg: argument
 * Return: 1
*/

int char_conversion(va_list arg)
{
	char a;

	a = va_arg(arg, int);
	write(STDOUT_FILENO, &a, 1);
	return (1);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int a, count = 0;

	va_start(arg, format);

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			count++;
			write(STDOUT_FILENO, &format[a], 1);
		}
		else if (format[a] == '%')
		{
			if (format[a + 1] == 'c')
			{
				count += char_conversion(arg);
				a++;
			}
		}
	}
	va_end(arg);
	return (count);
}

