#include "variadic_functions.h"

/**
 * print_all - print
 * @format: the separator to use for printing
 *
 * Description: print all the strings given using the
 * separator
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list vl;
	unsigned int i;
	char *s, *separator = ", ";

	va_start(vl, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i + 1] == '\0')
			separator = "";

		switch (format[i])
		{
			case 'c':
				printf("%c%s", va_arg(vl, int), separator);
				break;
			case 'i':
				printf("%d%s", va_arg(vl, int), separator);
				break;
			case 'f':
				printf("%f%s", va_arg(vl, double), separator);
				break;
			case 's':
				s = va_arg(vl, char *);
				if (s == NULL)
					s = "(nil)";
				printf("%s%s", s, separator);
			default:
				break;
		}
	}

	printf("\n");
	va_end(vl);
}
