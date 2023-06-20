#include "main.h"

/**
 * _isalpha- Will check the alphabet
 *  @n: charachter to be checked
 *
 *  Return: 1 if character is a letter, 0 otherwise
 */

int _isalpha(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
		return (1);
	else
		return (0);
}
