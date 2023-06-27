#include "variadic_functions.h"

/**
 * print_strings - print variable number of strings
 * @separator: the separator to use
 * @n: number of integers
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list vl;
	unsigned int i = 1;
	char *s;

	va_start(vl, n);

	while (i <= n)
	{
		printf("%s", (s = va_arg(vl, char *)) == NULL ? "(nil)" : s);

		if (separator != NULL && i != n)
			printf("%s", separator);

		i++;
	}

	printf("\n");
	va_end(vl);
}
