#include "3-calc.h"

/**
 * main - operate on two numbers
 * @argc: integer
 * @argv: array of strings
 * Return: returns 0
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	char sym[2];
	int (*f)(int, int);

	if (argc != 4)
	{
		puts("Error");
		exit(98);
	}
	if (
		(argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' &&
		argv[2][0] != '/' && argv[2][0] != '%') || argv[2][1] != '\0'
	)
	{
		puts("Error");
		exit(99);
	}

	if ((argv[2][0] == '/' || argv[2][0] == '%') && atoi(argv[3]) == 0)
	{
		puts("Error");
		exit(100);
	}

	sym[0] = argv[2][0];
	sym[1] = '\0';

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	f = get_op_func(sym);
	result = f(a, b);

	printf("%d\n", result);
	return (0);
}
