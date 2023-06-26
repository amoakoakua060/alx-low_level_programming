#include "main.h"

/**
 * free_grid - free memory allocated
 * @grid: array of int arrays
 * @height: int and size of matrix
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	if (height <= 0)
		return;

	i = 0;
	while (i < height)
	{
		free(*(grid + i));
		i++;
	}

	free(grid);
}
