#include "main.h"

/**
 * array_range - range of integers as array
 * @min: integer
 * @max: integer
 * Return: int *
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i, j;

	if (max < min)
		return (NULL);

	ptr = malloc((max - min + 1) * sizeof(int));
	if (ptr == NULL)
		return (NULL);

	for (j = 0, i = min; i <= max; i++, j++)
		ptr[j] = i;

	return (ptr);
}
