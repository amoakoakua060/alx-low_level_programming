#include "variadic_functions.h"

/**
 * print_numbers - print variable numbers
 * @separator: the separator to use
 * @n: number of integers
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list vl;
	unsigned int i = 0;

	va_start(vl, n);

	while (i <= n)
	{
		printf("%d", va_arg(vl, int));

		if (separator != NULL && i != n)
			printf("%s", separator);

		i++;
	}

	printf("\n");
	va_end(vl);
}
