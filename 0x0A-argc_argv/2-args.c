#include <stdio.h>

/**
 * main - print the arguments of the program
 * @argc: count of arguments
 * @argv: array of string arguments
 * Return: returns 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i = 0;

	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return (0);
}
