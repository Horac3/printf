#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_binary- produces output according to a format.
 * @n: parameter for unsigned d
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int print_binary(unsigned int n)
{
	int count = 0;

	if (n > 1)
	{
		count += print_binary(n >> 1);
	}
	_putchar((n & 1) + '0');

	count++;

	return (count);
}

/**
 * binary_printf - produces output according to a format.
 * @format: A string containing zero or more directives
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */


int binary_printf(const char *format, ...)
{
	const char *p;

	int count = 0;

	va_list args;

	p = format;

	va_start(args, format);

	for (; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;

			if (*p == 'b')
			{
				unsigned int n =
					va_arg(args, unsigned int);

				count += print_binary(n);
			}
		}
		else
		{
			_putchar(*p);

			count++;
		}
	}

	va_end(args);

	return (count);
}
