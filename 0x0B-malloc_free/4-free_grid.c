#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - frees second array
 * @grid: second grid
 * @height: height of the grid
 * Description: frees memory of grid
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
