#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *main - Entry point
 *Return: Must be Zero 0 (Successfully)
*/

int main(void)

{
	int b, m;

	for (b = '0'; b < '9'; b++)
	{

		for (m = b + 1; m <= '9'; m++)
		{
			if (m != b)
			{
				putchar(b);
				putchar(m);
				if (b == '8' && m == '9')
					continue;
						putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);

}
