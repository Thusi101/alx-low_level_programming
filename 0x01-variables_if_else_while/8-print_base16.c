#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *main - Entry point
 *Return: Must be Zero 0 (Successfully)
*/

int main(void)

{
	int h;
	char low;

	for (h = '0'; h <= '9'; h++)
		putchar(h);

	for (low = 'a'; low <= 'f'; low++)
		putchar(low);
	putchar('\n');

	return (0);
}
