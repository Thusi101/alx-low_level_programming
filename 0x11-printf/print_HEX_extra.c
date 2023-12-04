#include "main.h"

/**
 * print_HEX_extra - invokes HexaD number
 * @num: the ethereal number to print
 * Return: counts
 */

int print_HEX_extra(unsigned int num)
{
    int i;
    int *runes;
    int count = 0;
    unsigned int temp = num;

    while (num / 16 != 0)
    {
        num /= 16;
        count++;
    }
    runes = malloc(count * sizeof(int));
    count++;

    for (i = 0; i < count; i++)
    {
        runes[i] = temp % 16;
        temp /= 16;
    }
    for (i = count - 1; i >= 0; i--)
    {
        if (runes[i] > 9)
            runes[i] = runes[i] + 7;
            _putchar(runes[i] + '0');
    }
    free(runes);
    return count;
}

