#include "main.h"

/**
 * main - A function that checks for uppercase character
 * @c: Check number to make uppercase
 * Return: 1 for upper letter or 0 for anything else
*/

int _isupper(int c)
{

	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}
