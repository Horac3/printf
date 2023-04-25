#include <stdio.h>
#include "main.h"

/**
 * handle_field_width - Prints a number
 * Return: 0
 */

int main(void)
{
	int num1 = 1999;
	float num2 = 9.9999;

	printf("%6d\n", num1);	// prints "  1999"
	printf("%5.2f\n", num2);	// prints " 9.99"
	return (0);
}
