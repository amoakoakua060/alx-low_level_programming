#include <stdio.h>
#include <stdlib.h>

/**
 * get_number_of_coins - get the change
 * @cent: current cent value
 * @amt: amount being changed
 * Return: returns 0 (Success)
 */
int get_number_of_coins(int cent, int amt)
{
	int nextcent, mod, n;

	switch (cent)
	{
		case 25:
			nextcent = 10;
			break;
		case 10:
			nextcent = 5;
			break;
		case 5:
			nextcent = 2;
			break;
		case 2:
			nextcent = 1;
			break;
		default:
			break;
	}
	mod = amt % cent;
	n = amt / cent;
	if (!mod)
		return (n);
	return (get_number_of_coins(nextcent, amt - (n * cent)) + n);
}

/**
 * main - get change in terms of number of coins
 * @argc: count of arguments
 * @argv: array of string arguments
 * Return: returns 0 (Success)
 */
int main(int argc, char *argv[])
{
	int number;

	if (argc != 2)
	{
		puts("Error");
		return (1);
	}

	number = atoi(argv[1]);

	if (number < 0)
		puts("0");
	else
		printf("%d\n", get_number_of_coins(25, number));

	return (0);
}
