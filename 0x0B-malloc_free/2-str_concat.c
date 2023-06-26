#include "main.h"

/**
 * str_len - get length of string
 * @s: pointer to string
 * Return: unsigned int
 */
unsigned int str_len(char *s)
{
	unsigned int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * str_concat - concatenate strings
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: pointer to char
 */
char *str_concat(char *s1, char *s2)
{
	char *ptr, a[] = "";
	unsigned int i, l1 = 0, l2 = 0;

	if (s1 == NULL)
		s1 = a;

	if (s2 == NULL)
		s2 = a;

	l1 = (unsigned int) str_len(s1);
	l2 = (unsigned int) str_len(s2);

	ptr = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!ptr)
		return (NULL);

	i = 0;
	while (i < l1)
	{
		*(ptr + i) = s1[i];
		i++;
	}

	i = 0;
	while (i < (l1 + l2))
	{
		*(ptr + i + l1) = s2[i];
		i++;
	}

	if (i == l2 + l1)
		*(ptr + i) = '\0';

	return (ptr);
}
