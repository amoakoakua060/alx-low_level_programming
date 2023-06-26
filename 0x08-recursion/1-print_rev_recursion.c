#include "main.h"

/**
 * _print_rev_recursion - prints chars recursively
 * in reverse
 * @s: pointer to char
 */
void _print_rev_recursion(char *s)
{

	if (*s == '\0')
	{
		return;
	}

	_print_rev_recursion(s + 1);
	_putchar(*s);
}
