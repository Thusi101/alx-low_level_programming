#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 *
 * This function takes an unsigned long integer and prints its binary representation.
 * It uses bitwise shift operations for efficiency and checks for leading zeros.
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	int msb_pos = sizeof(n) * 8 - 1;
	while ((n & (1UL << msb_pos)) == 0)
		msb_pos--;

	while (msb_pos >= 0)
		_putchar(((n >> msb_pos--) & 1) ? '1' : '0');
}
