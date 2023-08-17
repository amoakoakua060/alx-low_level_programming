#include "lists.h"

/**
 * print_dlistint - print the n members of the dlistint_t
 * @h: node of a dlistint link
 * Return: size_t
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t length = 0;

	for (; h != NULL; h = h->next, length++)
		printf("%d\n", h->n);

	return (length);
}
