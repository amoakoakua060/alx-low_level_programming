#include "variadic_functions.h"

/**
 * sum_them_all - summation of numbers
 * @n: number of integers
 * Return: int
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list vl;
	unsigned int i = 1, sum = 0;

	if (n == 0)
		return (0);

	va_start(vl, n);

	while (i <= n)
	{
		sum += va_arg(vl, int);
		i++;
	}

	va_end(vl);
	return (sum);
}
