#include <stdio.h>

/**
 * main - print the number of arguments of the program
 * @argc: count of arguments
 * @argv: array of string arguments
 * Return: returns 0 (Success)
 */
int main(int argc, __attribute__((unused)) char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
