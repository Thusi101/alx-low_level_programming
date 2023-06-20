#include "main.h"
#include <unistd.h>

/**
 * _putchar.c - To write the charater _putchar to stdout
 * @p: the character to print
 * Return: On Success 1
 * On error, -1 is returned, and errno is set appropriatly
 */

int _putchar(char p)
{
	return (write(1, &p, 1));
}
