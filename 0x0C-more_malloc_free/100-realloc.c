#include "main.h"

/**
 * _realloc - reallocation of memory
 * @ptr: pointer to memory
 * @old_size: integer
 * @new_size: integer
 * Return: void *
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i, min;

	i = 0, min = old_size < new_size ? old_size : new_size;

	if (ptr == NULL)
		return (malloc(new_size));
	else if (old_size == new_size)
		return (ptr);
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(new_size * sizeof(char));
	if (p == NULL)
		return (NULL);

	while (i < min)
	{
		*(p + i) = *(((char *) ptr) + i);
		i++;
	}

	free(ptr);
	return ((void *) p);
}
