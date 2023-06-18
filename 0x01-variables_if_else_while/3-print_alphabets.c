#include <stdio.h>
/**
 * main - Entry point
 * Return: Must be Zero 0 (Successfully)
*/

int main(void)
{
	char m;

	char k;

	m = 'a';
	k = 'A';

	while (m <= 'z') {
			putchar(m);
			m++;
	}
			while (k <= 'Z')
			{
				putchar (k);
				k++;
			}
			
	putchar('\n');
	return (0);
}
