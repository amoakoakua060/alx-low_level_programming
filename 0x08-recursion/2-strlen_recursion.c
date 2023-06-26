#include "main.h"

/**
 * _strlen_recursion - using recursion to
 * get the length of string
 * @s: pointer to char
 * Return: int
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	return (1 + _strlen_recursion(s + 1));
}
