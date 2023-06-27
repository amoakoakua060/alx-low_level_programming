#include <stdio.h>
#include <stdlib.h>

/**
 * main - print opcodes
 * @argc: integer
 * @argv: array of strings
 * Return: returns 0
 */
int main(int argc, char **argv)
{
	int n_bytes, i = 0;
	char *str = (char *) main;

	if (argc != 2)
	{
		puts("Error");
		exit(1);
	}

	n_bytes = atoi(argv[1]);
	if (n_bytes < 0)
	{
		puts("Error");
		exit(2);
	}

	while (i < n_bytes)
	{
		printf("%02x", str[i] & 0xff);

		if (i + 1 != n_bytes)
			printf(" ");

		i++;
	}
	printf("\n");

	return (0);
}
