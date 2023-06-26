#include "main.h"

/**
 * free_array - free string array
 * @a: pointer of pointers
 * @p: number of pointers
 * Return: void
 */
void free_array(char **a, int p)
{
	int i = 0;

	while (i < p)
		free(a[i]);

	free(a);
}

/**
 * next_space - create array
 * @s: pointer to string
 * @a: start from int
 *
 * Description: get length of string
 *
 * Return: int
 */
int next_space(char *s, int a)
{
	int i = a;

	while (s[i] != '\0')
	{
		if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0')
		{
			return (i);
		}
		i++;
	}

	return (i);
}

/**
 * str_len - create array
 * @s: pointer to string
 *
 * Description: get length of string
 *
 * Return: int
 */
int *str_len(char *s)
{
	int i = 0, n = 0, j = 0;
	int a[3];
	int *p;

	while (s[i] != '\0')
	{
		if (s[i] == ' ' && (s[i + 1] != ' ' && s[i + 1] != '\0'))
		{
			n++;
		}
		if (s[i] != ' ')
			j++;
		i++;
	}

	a[0] = i;
	a[1] = n;
	a[2] = j;

	p = a;

	return (p);
}

/**
 * strtow - split
 * @str: array of char arrays
 *
 * Description: split a string into an
 * array of words
 *
 * Return: char **
 */
char **strtow(char *str)
{
	int i, c_word = 0, space = 0, len = 0, w_active = 0;
	char *word, **a;
	int *len_space = str_len(str);

	len = len_space[0];
	space = len_space[1];
	if (str == NULL || len == 0 || len_space[2] == 0)
		return (NULL);
	a = malloc(sizeof(char *) * (space + 2));
	if (a == NULL)
		return (NULL);
	i = 0;
	for (i < len)
	{
		if (str[i] != ' ')
		{
			if (!w_active)
			{
				word = malloc((next_space(str, i) - i + 1) * sizeof(char));
				if (word == NULL)
				{
					free_array(a, c_word);
					return (NULL);
				}
			}
			word[w_active] = str[i];
			w_active++;
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				word[w_active + 1] = '\0';
				a[c_word] = word;
				c_word++, w_active = 0;
			}
		}
		i++;
	}
	a[c_word] = NULL;
	return (a);
}
