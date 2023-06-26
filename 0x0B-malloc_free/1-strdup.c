#include "main.h"

/**
 * _strdup - create array in heap memory
 * @str: string to make a copy of
 * Return: pointer to char
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int i, l = 0;

	if (str == NULL)
		return (NULL);

	while (str[l] != '\0')
		l++;

	l++;
	ptr = malloc(l * sizeof(char));
	if (!ptr)
		return (NULL);

	i = 0;
	while (i < l + 1)
	{
		*(ptr + i) = *(str + i);
		i++;
	}

	return (ptr);
}
