#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiply two numbers
 * @argc: count of arguments
 * @argv: array of string arguments
 * Return: returns 0 (Success)
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		puts("Error");

	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));

	return (0);
}
