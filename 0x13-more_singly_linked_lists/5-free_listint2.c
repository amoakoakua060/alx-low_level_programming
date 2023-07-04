#include "lists.h"

/**
 * free_listint - free
 * @h: first listint_t node
 */
void free_listint(listint_t *h)
{
	if (h == NULL)
		return;

	if (h->next != NULL)
		free_listint(h->next);

	free(h);
}

/**
 * free_listint2 - free
 * @head: pointer to first listint_t node
 */
void free_listint2(listint_t **head)
{
	if (head == NULL)
		return;

	free_listint(*head);

	*head = NULL;
}
