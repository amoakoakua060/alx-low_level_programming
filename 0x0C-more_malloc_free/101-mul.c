#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _is_zero - determines if any number is zero
 * @argv: argument vector.
 * Return: no return.
 */
void _is_zero(char *argv[])
{
	int i, isn1 = 1, isn2 = 1;

	for (i = 0; argv[1][i]; i++)
		if (argv[1][i] != '0')
		{
			isn1 = 0;
			break;
		}

	for (i = 0; argv[2][i]; i++)
		if (argv[2][i] != '0')
		{
			isn2 = 0;
			break;
		}

	if (isn1 == 1 || isn2 == 1)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * init_array - set memery to zero
 * @ar: char array.
 * @lar: length of the char array.
 * Return: pointer of a char array.
 */
char *init_array(char *ar, int lar)
{
	int i = 0;

	for (i = 0; i < lar; i++)
		ar[i] = '0';
	ar[lar] = '\0';
	return (ar);
}

/**
 * check_num - determines length of the number
 * @argv: arguments vector.
 * @n: row of the array.
 * Return: length of the number.
 */
int check_num(char *argv[], int n)
{
	int j;

	for (j = 0; argv[n][j]; j++)
		if (!isdigit(argv[n][j]))
		{
			printf("Error\n");
			exit(98);
		}

	return (j);
}

/**
 * main - program that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int ln1, ln2, lstr, add, addl, i, j, k, ca;
	char *str;

	if (argc != 3)
		printf("Error\n"), exit(98);
	ln1 = check_num(argv, 1), ln2 = check_num(argv, 2);
	_is_zero(argv), lstr = ln1 + ln2, str = malloc(lstr + 1);
	if (str == NULL)
		printf("Error\n"), exit(98);
	str = init_array(str, lstr);
	k = lstr - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;
	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (addl > 0)
			{
				add = (str[k] - '0') + addl;
				if (add > 9)
					str[k - 1] = (add / 10) + '0';
				str[k] = (add % 10) + '0';
			}
			i = ln1 - 1, j--, addl = 0, ca++, k = lstr - (1 + ca);
		}
		if (j < 0)
		{
			if (str[0] != '0')
				break;
			lstr--;
			free(str), str = malloc(lstr + 1), str = init_array(str, lstr);
			k = lstr - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;
		}
		if (j >= 0)
		{
			add = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (str[k] - '0') + addl;
			addl = add / 10, str[k] = (add % 10) + '0';
		}
	}
	printf("%s\n", str);
	return (0);
}
