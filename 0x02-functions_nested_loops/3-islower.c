#include "main.h"

/**
 * _islower - checks if a character is lowercase
 * @p: the character
 * Return: 1 if letter is lowercase, 0 if not
 */

int _islower(int p)
{
	int p;

	if (p >= 'a' && p <= 'z')
		return (1);
	else
		return (0);
}
