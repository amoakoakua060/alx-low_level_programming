#include "main.h"

/**
 * _pow - get power
 * @i: int
 * Return: unsigned int
 */
unsigned int _pow(int i)
{
	unsigned int res = 1;

	while (i != 0)
	{
		res *= 2;
		i--;
	}

	return (res);
}

/**
 * convert_to_int - convertion
 * @str: binary as string
 * @result: pointer to unsigned int
 * @len: unsigned int
 */
void convert_to_int(
	unsigned int *result, const char *str, unsigned int len
)
{
	int i = 0, j = 0;

	while (str[i] != '\0')
	{
		j++;
		*result = *result + ((str[i] - '0') * _pow(len - j));
		i++;
	}
}

/**
 * is_invalid - check for binary
 * @b: binary as string
 * Return: int
 */
int is_invalid(const char *b)
{
	int i = 0, j = 1;

	while (b[i] != '\0')
	{
		if (b[i] != '1' && b[i] != '0')
			return (j);
		i++;
	}
	j--;
	return (j);
}

/**
 * binary_to_uint - convertion
 * @b: binary as string
 * Return: unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0, len = 0;

	if (b == NULL || is_invalid(b))
		return (res);

	while (b[len] != '\0')
		len++;

	convert_to_int(&res, b, len);

	return (res);
}
