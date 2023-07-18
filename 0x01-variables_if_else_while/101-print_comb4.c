#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *main - Entry point
 *Return: Must be Zero 0 (Successfully)
*/

int main(void)

{

	int a, b, m;

	for (a = '0'; a < '9'; a++)
	{

		for (b = a + 1; b <= '9'; b++)
		{

			for (m = b + 1; m <= '9'; m++)
			{
				if ((b != a) != m)
				{
					putchar(a);
					putchar(b);
					putchar(m);
					if (a == '7' && b == '8')
						continue;
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
