#include <stdio.h>

int main(void)
{
	char c = 'a';

	while (c <= 'z' || c <= 'Z')
	{
		putchar(c);
		c++;
			if (c > 'z')
			{
				c = 'A';
			}
				break;
	}

	putchar('\n');

	return 0;
}
