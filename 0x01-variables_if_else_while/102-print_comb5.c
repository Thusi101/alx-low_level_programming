#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *main - Entry point
 *Return: Must be Zero 0 (Successfully)
*/

int main(void)

{
	int s, w;

	for (s = 0; s <= 98; s++)
	{

		for (w = s + 1; w <= 99; w++)
		{
			putchar((s / 10) + '0');
			putchar((s % 10) + '0');
			putchar(' ');
			putchar((w / 10) + '0');
			putchar((w % 10) + '0');
			if (s == 98 && w == 99)
				continue;
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
