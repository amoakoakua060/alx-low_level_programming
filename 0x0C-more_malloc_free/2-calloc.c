#include "main.h"

/**
 * _calloc - allocate
 * @nmemb: integer
 * @size: integer
 * Return: void *
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (; i < nmemb * size; i++)
		*(ptr + i) = 0;

	return ((void *) ptr);
}
