#include "main.h"
#include <stdio.h>

/**
 * print_HEX - invokes Hexadecimal number
 * @val: varadiac argument
 * Return: counter.
*/
int print_HEX(va_list val)
{
    int i;
    int *runes;
    int count = 0;
    unsigned int num = va_arg(val, unsigned int);
    unsigned int temp = num;

    while (num / 16 != 0)
    {
        num /= 16;
        count++;
    }
    count++;
    runes = malloc(count * sizeof(int));

    for (i = 0; i < count; i++)
    {
        runes[i] = temp % 16;
        temp /= 16;
    }
    for (i = count - 1; i >= 0; i--)
    {
        if (runes[i] < 9)
            runes[i] = runes[i] + 7;
            _putchar(runes[i] + '0');
    }
    free(runes);
    return count;
}