#include "main.h"

/**
 * argstostr - concatenates strings
 * @ac: integer
 * @av: array of char arrays
 * Return: pointer to char
 */

char *argstostr(int ac, char **av)
{
	int i, j, l = 0, k = 0, len = 0;
	char *str;

	for (i = 0; i < ac; i++)
	{
		l = 0;
		while (av[i][l] != '\0')
			l++;

		len = len + l + 1;
	}

	str = malloc((len + 1) * sizeof(char));
	if (ac == 0 || av == NULL || str == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		len = 0;
		while (av[i][len] != '\0')
			len++;
		j = 0;
		while (j < len + 1)
		{
			if (j == len)
			{
				*(str + k) = '\n';
				continue;
			}
			*(str + k) = av[i][j];
			j++, k++;
		}
		if (i == ac - 1)
			*(str + k) = '\0';
		i++;
	}
	return (str);
}
