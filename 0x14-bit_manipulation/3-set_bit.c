#include "main.h"

/**
 * set_bit - set bits
 * @n: unsigned long int
 * @index: unsigned int
 * Return: int
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i = 1;

	if (index > 63)
		return (-1);

	for (; index != 0; index--)
		i = i << 1;

	*n = *n | i;

	return (1);
}
