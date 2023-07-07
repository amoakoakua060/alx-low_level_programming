#include <stdio.h>

/**
 * get_endianness - determine endianness
 * Return: 0 or 1
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *check = (char *)&i;

	if (*check)
		return (1);

	return (0);
}
