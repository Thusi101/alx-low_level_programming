#include "main.h"
#include <unistd.h>

/**
 * _putchar - A function that mimics the behavior of putchar.
 * @c: The character to be written to stdout.
 *
 * This function is a custom implementation of the putchar function. 
 * 
 * Return: On success, it returns 1 (the number of characters written).
 *
 * On error, it returns -1 and sets errno appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

