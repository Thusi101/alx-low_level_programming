#include <stdio.h>
/**
 * main - Entry point
 * Return: Must be Zero 0 (Successfully)
*/

int main(void)
{
	char m = 'a';

	while (m <= 'z' || m <= 'Z')
	{
		putchar(m);
		m++;
			if (m > 'z')
			{
				m = 'A';
			}
				break;
	}

	putchar('\n');

	return 0;
}
