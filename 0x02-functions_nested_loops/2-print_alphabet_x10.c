#include "main.h"

/**
 * print_alphabet_x10 - prints alpha 10 times
 * Return: void
 */

void print_alphabet_x10(void)

{
	int ten = 0;

	char pha;

	for (ten = 0; ten <= 9; ten++)
	{
	for (pha = 'a'; pha <= 'z'; pha++)
		_putchar(pha);
	_putchar('\n');
	}
}
