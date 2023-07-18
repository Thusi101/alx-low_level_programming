#include "main.h"

/**
 * print_last_digit - prints the last digit
 * @ld: the number\Return: value of the last digit
 * Return: value of the last digit
 */

int print_last_digit(int ld)
{
	int last;

	last = ld % 10;
	if (last < 0)
	{
		last = last * -1;
	}
	_putchar(last + '0');

	return (last);
}
