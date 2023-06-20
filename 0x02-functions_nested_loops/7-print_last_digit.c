#include "main.h"

/**
 * print_last_digit - prints the last digit
 * @d: the number\Return: value of the last digit
 * Return: value of the last digit
 */

int print_last_digit(int d)
{
	int ld = d % 10;

	if (ld < 0)
		ld *= -1;

	_putchar(ld + '0');

	return (0);
}
