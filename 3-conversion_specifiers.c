#include <stdarg.h>
#include <stdio.h>
#include "main.h"


/**
 * print_unsigned - prints an unsigned integer
 * @n: the unsigned integer to print
 *
 * Return: the number of characters printed
 */
int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10);

	count += _putchar((n % 10) + '0');
	return (count);
}

/**
 * print_octal - prints an unsigned integer in octal form
 * @n: the unsigned integer to print
 *
 * Return: the number of characters printed
 */
int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal(n / 8);
	count += _putchar((n % 8) + '0');
	return (count);
}

/**
 * print_hex - prints an unsigned integer in hexadecimal form
 * @n: the unsigned integer to print
 * @uppercase: a flag indicating whether to use uppercase letters
 *
 * Return: the number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	char digit;

	if (n / 16)
		count += print_hex(n / 16, uppercase);
	digit = (n % 16 < 10) ? (n % 16 + '0') :
		(n % 16 - 10 + (uppercase ? 'A' : 'a'));
	count += _putchar(digit);
	return (count);
}

/**
 * specifier_printf - prints a formatted string to the standard output stream
 * @format: the format string to print
 * @...: a variable number of arguments to print
 *
 * Return: the number of characters printed
 */

int specifier_printf(const char *format, ...)
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
				case 'u':
					count += print_unsigned
						(va_arg(args, unsigned int));
					break;
				case 'o':
					count += print_octal
						(va_arg(args, unsigned int));
					break;
				case 'x':
					count += print_hex
						(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					count += print_hex
						(va_arg(args, unsigned int), 1);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

