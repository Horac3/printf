#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: A string that specifies the format of the output.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'u':
					count += print_unsigned_int(va_arg(args, unsigned int));
					break;
				case 'o':
					count += print_octal(va_arg(args, unsigned int));
					break;
				case 'x':
					count += print_hex(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					count += print_hex(va_arg(args, unsigned int), 1);
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, &(*format), 1);
					break;
			}
		}
		else
			count += write(1, &(*format), 1);
		format++;
	}
	va_end(args);
	return (count);
}
