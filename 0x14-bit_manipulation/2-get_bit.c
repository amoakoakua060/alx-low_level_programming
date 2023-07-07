#include "main.h"

/**
 * get_bit - get bit at an index
 * @n: unsigned long int
 * @index: unsigned int
 * Return: int
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	for (; n > 1; n = n >> 1, index--)
		if (index == 0)
			break;

	if (index != 0)
		return (0);

	return (n & 1 ? 1 : 0);
}
