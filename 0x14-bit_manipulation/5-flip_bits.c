#include "main.h"

/**
 * _get - get bit
 * @n: unsigned long int
 * @index: unsigned int
 * Return: int
 */
int _get(unsigned long int n, unsigned int index)
{
	while (n > 1)
	{
		if (index == 0)
			break;
		n = n >> 1;
		index--;
	}

	if (index != 0)
		return (-1);

	return (n & 1 ? 1 : 0);
}

/**
 * _count - count bits
 * @count: pointer unsigned int
 * @n: pointer unsigned long int
 * @m: pointer unsigned long int
 * Return: int
 */
void _count(
	unsigned int *count, unsigned long int *n,
	unsigned long int *m
)
{
	if (_get(*m, 0) != _get(*n, 0))
		*count = *count + 1;

	*m = *m >> 1;
	*n = *n >> 1;
}

/**
 * flip_bits - flip bits
 * @n: unsigned long int
 * @m: unsigned long int
 * Return: unsigned int
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int i;
	unsigned int count = 0;

	i = n >= m ? n : m;

	for (; i > 1; i = i >> 1)
		_count(&count, &m, &n);

	_count(&count, &m, &n);

	return (count);
}
