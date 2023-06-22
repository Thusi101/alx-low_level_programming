#include "main.h"

/**
 * main - A function that checks for uppercase character
 * @c: Check uppercase
 * Return: 0 (Success)
*/

int _isupper(int c)
{

	if ( c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}
