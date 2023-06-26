#include "main.h"

/**
 * factorial - recursive factorization
 * @n: integer for which to find factorial
 * Return: returns int
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
