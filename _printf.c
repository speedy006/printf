#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
	}
	va_end(arg);
	return (count);
}

/**
 * main - test case without conversions
 * Return: 0
*/

int main(void)
{
	_printf("hello world\n");
	_printf("0\n");
	return (0);
}
