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
 * string_conversion - deals with %s specifier
 * @arg: argument
 * Return: count
*/

int string_conversion(va_list arg)
{
	char *a;
	int x, count = 0;

	a = va_arg(arg, char *);
	for (x = 0; a[x] != '\0'; x++)
	{
		write(STDOUT_FILENO, &a[x], 1);
		count++;
	}

	return (count);
}

/**
 * special_format - deals with %% specifier
 * Return: 1
*/

int special_format(void)
{
	char a;

	a = '%';

	write(STDOUT_FILENO, &a, 1);
	return (1);
}

/**
 * integer_conversion - deals with %d specifier
 * @arg: argument
 * Return: count
*/

int integer_conversion(va_list arg)
{
	int digit = va_arg(arg, int);
	char numbers[20];
	int count = 0, x;

	if (digit < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		digit = -digit;
		count++;
	}

	do {
		numbers[count++] = '0' + (digit % 10);
		digit /= 10;
	} while (digit > 0);

	for (x = count - 1; x >= 0; x--)
	{
		write(STDOUT_FILENO, &numbers[x], 1);
	}
	return (count);
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
			else if (format[a + 1] == 's')
			{
				count += string_conversion(arg);
				a++;
			}
			else if (format[a + 1] == '%')
			{
				count += special_format();
				a++;
			}
			else if (format[a + 1] == 'd')
			{
				count += integer_conversion(arg);
				a++;
			}
		}
	}
	va_end(arg);
	return (count);
}

