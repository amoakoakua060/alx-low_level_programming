#include "lists.h"

/**
 * print_listint - print singly linked lists
 * @h: listint linked list
 * Return: size_t
 */
size_t print_listint(const listint_t *h)
{
	size_t elem = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		elem++;
		h = h->next;
	}

	return (elem);
}
