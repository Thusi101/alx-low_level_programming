#include <stdio.h>
/**
 * main -  a program that prints the size of various types compiled and run on;
 * Return 0 (Success);
 */
int main(void)
{
	char c;
	int i;
	long int li;
	long long int lli;
	float f;

printf("Size of a char: %lu 1 byte(s)\n", (unsigned long)sizeof(c));
printf("Size of a int: %lu 4 byte(s)\n", (unsigned long)sizeof(i));
printf("Size of a long int: %lu 8 byte(s)\n", (unsigned long)sizeof(li));
printf("Size of a long long int: %lu 8 byte(s)\n", (unsigned long)sizeof(lli));
printf("Size of a float: %lu 4 byte(s)\n", (unsigned long)sizeof(f));
return (0);
}
