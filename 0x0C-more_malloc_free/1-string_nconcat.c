#include "main.h"

/**
 * str_len - length
 * @s: pointer to string
 * Return: int
 */
int str_len(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * string_nconcat - concatenate
 * @s1: pointer to string
 * @s2: pointer to string
 * @n: integer
 * Return: char *
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int i = 0, j = 0, len = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	len = str_len(s1);
	ptr = malloc((len + n + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);

	while (i < len)
	{
		*(ptr + i) = s1[i];
		i++;
	}

	while (j < n)
	{
		*(ptr + i + j) = s2[j];
		j++;
	}

	*(ptr + len + n) = '\0';

	return (ptr);
}
