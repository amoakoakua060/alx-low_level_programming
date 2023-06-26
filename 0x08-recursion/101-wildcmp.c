#include "main.h"

/**
 * get_len - find the length of s
 * @s: char
 * Return: returns int
 */
int get_len(char *s)
{
	if ((*s) == '\0')
		return (0);

	return (1 + get_len(s + 1));
}

/**
 * has_ast - asteriks
 * @a: char
 *
 * Description: get characters after asteriks
 *
 * Return: int
 */
int has_ast(char *a)
{
	if (*a == '*')
		return (1 + has_ast(a + 1));
	else if (*a == '\0')
		return (0);

	return (0 + has_ast(a + 1));
}

/**
 * get_after_ast - asteriks
 * @a: char
 *
 * Description: get characters after asteriks
 *
 * Return: *char
 */
char *get_after_ast(char *a)
{
	if (*a == '*')
		return (get_after_ast(a + 1));

	return (a);
}

/**
 * get_last_char - last char
 * @a: pointer to string
 * @b: char
 * @c: pointer to string
 *
 * Description: determine position of charater
 *
 * Return: char *
 */
char *get_last_char(char *a, char b, char *c)
{
	if (*a == '\0' && *c != b)
	{
		return (a);
	}
	else if (*a == '\0' && *c == b)
	{
		if (*c != *(c - 1))
			return (c);

		return (get_last_char(a, b, c - 1));
	}

	if (*a == b)
		c = a;

	return (get_last_char(a + 1, b, c));
}

/**
 * wildcmp - comparing to strings
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: returns int
 */
int wildcmp(char *s1, char *s2)
{
	int l1 = get_len(s1), l2 = get_len(s2);
	int h_ast = has_ast(s2);

	if (!h_ast && l1 != l2)
		return (0);

	if (h_ast == l2)
		return (1);

	if (s1 != s2 && s2 - 1 != '*' && s2 != '*' && s2 + 1 != '\0')
		return (0);
	else if (s1 == '\0' && s2 == '*' && s2 + 1 == '\0')
		return (1);
	else if (s1 == s2 && s1 == '\0')
		return (1);
	else if (s2 != '\0' && s2 + 1 != '*' && s1 == '\0')
		return (0);
	else if (s2 == '*' && s2 + 1 == '\0')
		return (1);

	if (s2 == '*' && s2 + 1 != '\0' &&  s2 + 2 == '*')

		return (wildcmp(s1, s2 + 1));
	else if (s2 == '*')
	{
		s2 = get_after_ast(b + 1);
		s1 = get_last_char(a, *b, a);

		if (s1 == '\0' && !s2)
			return (1);

		return (wildcmp(s1, s2));
	}
	else
		return (wildcmp(s1 + 1, s2 + 1));
	/* return (wildcmp(s1, s2)); */
}
