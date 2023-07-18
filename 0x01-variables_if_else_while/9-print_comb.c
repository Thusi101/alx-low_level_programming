#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *main - Entry point
 *Return: Must be Zero 0 (Successfully)
*/

int main(void)

{
	int p;

	for (p = '0'; p <= '9'; p++)
	{
		putchar(p);
		if (p != '9')
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);

}
