#include "lists.h"

/**
 * delete_dnodeint_at_index - delete node at index
 * @head: pointer to first node of a dlistint list
 * @index: position of node in the list
 * Return: int
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL || index < i)
		return (-1);

	for (tmp = *head; tmp != NULL; i++, tmp = tmp->next)
		if (i == index)
		{
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (index == 0)
				*head = tmp->next;
			free(tmp);
			return (1);
		}
	return (-1);
}
