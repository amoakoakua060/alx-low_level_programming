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
 * is_equal - are two strings equal
 * @a: char
 * @b: char
 * Return: returns int
 */
int is_equal(char *a,  char *b)
{
	if (*a != *b)
		return (0);

	if (*(b + 1) == '\0')
		return (1);

	return (is_equal(a - 1, b + 1));
}

/**
 * is_palindrome - is string a palindrome
 * @s: pointer to string
 * Return: returns int
 */
int is_palindrome(char *s)
{
	int mid, s_len = get_len(s);

	mid = s_len / 2;

	if (s_len == 0)
		return (0);

	return (is_equal(
			s + mid - 1,
			s_len % 2 == 0 ? s + mid : s + mid + 1
	));
}
