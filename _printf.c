#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: A string containing zero or more directives
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *s;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if
				(*format == 's')
				{
					s = va_arg(args, const char*);
					while (*s)
					{
						putchar(*s++);
						count++;
					}
				}
			else if
				(*format == '%')
				{
					putchar('%');
					count++;
				}
			else
			{

			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
