#include "main.h"

/**
 * create_array - create array and initialize with char
 * @size: number of bytes of the array
 * @c: char to initialize array with
 * Return: pointer to char
 */
char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i = 0;

	if (size == 0)
		return (NULL);

	ptr = malloc(size * sizeof(char));

	if (!ptr)
		return (NULL);

	while (i < size)
	{
		*(ptr + i) = c;
		i++;
	}

	return (ptr);
}
