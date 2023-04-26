#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					int c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					const char *s = va_arg(args, const char *);
					while (*s)
					{
						 putchar(*s++);
						 count++;
					}
					break;
				}
				case 'd':
				case 'i':
				{
					int d = va_arg(args, int);
					printf("%d", d);
					count += snprintf(NULL, 0, "%d", d);
					break;
				}
				case 'u':
				{
					 unsigned int u = va_arg(args, unsigned int);
					 printf("%u", u);
					 count += snprintf(NULL, 0, "%u", u);
					 break;
				}
				case 'x':
				{
					unsigned int x = va_arg(args, unsigned int);
					printf("%x", x);
					count += snprintf(NULL, 0, "%x", x);
					 break;
				}
				case 'X':
				{
					 unsigned int X = va_arg(args, unsigned int);
					 printf("%X", X);
					 count += snprintf(NULL, 0, "%X", X);
					 break;
				}
				case 'o':
				{
					unsigned int o = va_arg(args, unsigned int);
					printf("%o", o);
					count += snprintf(NULL, 0, "%o", o);
					break;
				}
				case 'f':
				{
					double f = va_arg(args, double);
					printf("%f", f);
					count += snprintf(NULL, 0, "%f", f);
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
				default:
				{
					putchar('%');
					putchar(*format);
					count += 2;
					break;
				}
			}
		}
		else
		{
			count _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _puts - used to output a string to the stdout
 * @str: the string
 * Return: the number of strings
 */

int _puts(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
