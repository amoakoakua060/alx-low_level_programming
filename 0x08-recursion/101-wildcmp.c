#include "main.h"

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
 * check_equality - checks if equal
 * @a: char
 * @b: char
 * Return: returns int
 */
int check_equality(char *a,  char *b)
{
	if (*a != *b && *(b - 1) != '*' && *b != '*' && *(b + 1) != '\0')
		return (0);
	else if (*a == '\0' && *b == '*' && *(b + 1) == '\0')
		return (1);
	else if (*a == *b && *a == '\0')
		return (1);
	else if (*b != '\0' && *(b + 1) != '*' && *a == '\0')
		return (0);
	else if (*b == '*' && *(b + 1) == '\0')
		return (1);

	if (*b == '*' && *(b + 1) != '\0' &&  *(b + 2) == '*')
	{

		return (check_equality(a, b + 1));
	}
	else if (*b == '*')
	{
		b = get_after_ast(b + 1);
		a = get_last_char(a, *b, a);

		if (*a == '\0' && !(*b))
			return (1);

		return (check_equality(a, b));
	}
	else
	{
		return (check_equality(a + 1, b + 1));
	}
}

/**
 * wildcmp - comparing to strings
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: returns int
 */
int wildcmp(char *s1, char *s2)
{
	int l1 = 0, l2 = 0;
	int h_ast = has_ast(s2);

	while (s1[l1] != '\0')
		l1++;
	while (s2[l2] != '\0')
		l2++;

	if (!h_ast && l1 != l2)
		return (0);

	if (h_ast == l2)
		return (1);

	return (check_equality(s1, s2));
}
