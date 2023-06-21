#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci number, starting with
 * 1 and 2, seperated by a comma followed by a space.
 * Return: Always 0
 */

int main(void)

{

	int count;
	unsigned long f = 0, f2 = 1, sum;
	unsigned long f_h1, f_h2, f2_h1, f2_h2;
	unsigned long h1, h2;
	
	for (count = 0; count < 92; count++)
	{
	sum = f + f2;
	printf("%lu, ", sum);
	f = f2;
	f2 = sum;
	}
	f_h1 = f / 1000000;
	f2_h1 = f2 / 1000000;
	f_h2 = f % 1000000;
	f2_h2 = f2 % 1000000;
	for (count = 93; count <= 99; count++)
	{
	h1 = f_h1 + f2_h1;
	h2 = f_h2 + f2_h2;
	if (f_h2 + f2_h2 > 9999999)
	{
	h1 += 1;
	h2 %= 1000000;
	}
	printf("%lu%lu", h1, h2);
	if (count != 98)
	printf(",");
	f_h1 = f2_h1;
	f_h2 = f2_h2;
	f2_h1 = h1;
	f2_h2 = h2;
	}
	printf("\n");
	return (0);
}
