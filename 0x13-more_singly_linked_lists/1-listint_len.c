#include "lists.h"

/**
 * listint_len - get length of link
 * @h: listint linked list
 * Return: size_t
 */
size_t listint_len(const listint_t *h)
{
	size_t elem = 0;

	while (h != NULL)
	{
		elem++;
		h = h->next;
	}

	return (elem);
}
