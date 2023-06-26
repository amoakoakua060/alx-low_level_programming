#include "main.h"

/**
 * is_square - performing square root
 * @i: integer
 * @j: integer
 * Return: returns int
 */
int is_square(int i, int j)
{
	if (j > 46340 * 2)
		return (is_square(i, j / 2));
	else if (j > 46340)
		return (is_square(i, j - 1));

	if (j * j == i)
		return (j);
	else if (j == 0 && i != j)
		return (-1);

	return (is_square(i, j - 1));
}

/**
 * _sqrt_recursion - calling recursive function
 * @n: integer
 * Return: returns int
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n < 2)
		return (n);

	return (is_square(n, n - 1));
}
