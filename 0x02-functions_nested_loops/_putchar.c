#include "main.h"
#include <unistd.h>

/**
 * 0-putchar.c - To write the charater _putchar to standard output
 * _putchar: the character to print
 *
 *Return: On success 1
 */

int _putchar(char p)
	
	return (write(1, &p, 1));
