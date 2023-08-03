#include "main.h"

/**
 * _count - count bits
 * @n: unsigned long int
 * Return: unsigned int
 */
unsigned int _count(unsigned long int n)
{
	unsigned int i = 1;

	while (n > 1)
	{
		n = n >> 1;
		i++;
	}

	return (i);
}

/**
 * clear_bit - clear bits of int
 * @n: unsigned long int
 * @index: unsigned int
 * Return: int
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i = 1;
	unsigned int a = 0, b = 1;

	if (index > 63)
		return (-1);

	a = _count(*n);
	for (; b != a; b = _count(i))
	{
		if (index == 0)
			break;
		i = i << 1;
		index--;
	}

	if (index == 0)
	{
		*n = *n | i;
		*n = *n ^ i;
	}

	return (1);
}
