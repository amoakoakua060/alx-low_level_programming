#include "main.h"

/**
 * malloc_checked - allocate
 * @b: size of memory to allocate
 * Return: void *
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);

	return (ptr);
}
