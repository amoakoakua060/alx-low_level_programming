#include "lists.h"

/**
 * get_dnodeint_at_index - get node from list at an index
 * @head: first node of a dlistint list
 * @index: position of node in the list
 * Return: dlistint_t *
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	if (head == NULL || index < i)
		return (NULL);

	for (tmp = head; tmp != NULL; i++, tmp = tmp->next)
		if (i == index)
			return (tmp);

	return (NULL);
}
