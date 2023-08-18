#include "lists.h"

/**
 * dlistint_len - get the number of members of the dlistint
 * @h: node of a dlistint link
 * Return: size_t
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t length = 0;

	for (; h != NULL; h = h->next)
		length++;

	return (length);
}
