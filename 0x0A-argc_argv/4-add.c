#include <stdio.h>
#include <stdlib.h>

/**
 * is_valid_number - check if is valid integer
 * @s: pointer to string
 * Return: returns 0 or 1
 */
int is_valid_number(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}

	return (1);
}

/**
 * main - add integers
 * @argc: count of arguments
 * @argv: array of string arguments
 * Return: returns 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i, num;
	unsigned int sum = 0;

	if (argc == 1)
	{
		puts("0");
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (!is_valid_number(argv[i]) || num < 0)
			{
				puts("Error");
				return (1);
			}

			num = atoi(argv[i]);

			sum += num;
		}

		printf("%u\n", sum);
	}
	return (0);
}
