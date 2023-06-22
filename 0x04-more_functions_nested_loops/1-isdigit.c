#include "main.h"

/**
 * _isdigit - Checks for a digit
 * @c: The character to b checked
 * Return: 1 for digit character or 0 for anthing else
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
