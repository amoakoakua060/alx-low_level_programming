#include "main.h"

/**
 * alloc_grid - create pointer to array of ints
 * @width: int and size of matrix
 * @height: int and size of matrix
 * Return: array of int arrays
 */
int **alloc_grid(int width, int height)
{
	int **ptr, *q_ptr, i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	ptr = malloc(height * sizeof(int *));
	if (ptr == NULL)
		return (NULL);

	i = 0;
	while (i < height)
	{
		q_ptr = malloc(width * sizeof(int));
		if (q_ptr == NULL)
		{
			for (j = 0; j < i; j++)
				free(*(ptr + j));

			free(ptr);

			return (NULL);
		}

		for (j = 0; j < width; j++)
			*(q_ptr + j) = 0;

		*(ptr + i) = q_ptr;
		i++;
	}

	return (ptr);
}
