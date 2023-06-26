#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates arguments
 * @ac: argument count.
 * @av: argument vector.
 * Return: pointer of an array of char
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int c, i, j, k;

	if (ac == 0)
		return (NULL);
	c = i = 0;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (NULL);

		for (j = 0; av[i][j] != '\0'; j++)
			c++;
		c++, i++;
	}

	str = malloc((c + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	for (i = j = k = 0; ia < c; j++, ia++)
	{
		if (av[i][j] == '\0')
		{
			str[k] = '\n';
			i++, k++;
			j = 0;
		}
		if (k < c - 1)
			str[k] = av[i][j];
	}
	str[k] = '\0';
	return (str);
}
