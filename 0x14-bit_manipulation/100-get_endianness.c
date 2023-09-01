#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	union
	{
		unsigned int i;
		char c[sizeof(unsigned int)];
	} u;
	u.i = 1;
	return (u.c[0]);
}
