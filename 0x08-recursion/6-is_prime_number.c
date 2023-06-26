#include "main.h"

/**
 * can_be_divided - divide
 * @a: integer
 * @b: integer
 * Return: returns int
 */
int can_be_divided(int a,  int b)
{
	if (b == 1)
		return (1);
	else if (a % b == 0)
		return (0);

	return (can_be_divided(a, b - 1));
}

/**
 * is_prime_number - calling recursive function
 * @n: integer
 * Return: returns int
 */
int is_prime_number(int n)
{
	if (n <= 2)
		return (0);

	return (can_be_divided(n, n - 1));
}
