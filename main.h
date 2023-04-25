#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_rev(char *str);
int _strlen(char *s);
int specifier_printf(const char *format, ...);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_binary(unsigned int n);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
        int flags, int width, int precision, int size)

#endif /* MAIN_H */
