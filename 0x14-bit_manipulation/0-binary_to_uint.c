#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: The binary number as a string.
 *
 * Return: The unsigned int representation of the binary number.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i, binary;

	if (!b)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
		;
	for (i--, binary = 1; i >= 0; i--, binary *= 2)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		num <<= 1;

		if (b[i] == '1')
			num += 1;
	}

	return (num);
}
