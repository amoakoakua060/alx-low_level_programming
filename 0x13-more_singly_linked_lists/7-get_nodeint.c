#include "lists.h"

/**
 * get_nodeint_at_index - get node at index
 * @head: first listint_t node
 * @index: index of node
 * Return: listint_t *
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}

	return (NULL);
}
