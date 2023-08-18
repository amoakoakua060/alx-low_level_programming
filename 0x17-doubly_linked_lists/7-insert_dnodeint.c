#include "lists.h"

/**
 * insert_dnodeint_at_index - insert node at idx
 * @h: pointer to first node of a dlistint list
 * @idx: position of node in the list
 * @n: data of the created node
 * Return: dlistint_t *
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp, *node;
	unsigned int i = 0, length = 0;

	if (h == NULL || idx < i)
		return (NULL);
	tmp = *h;
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}
	if (length < idx)
		return (NULL);
	if (*h == NULL || idx == 0)
		return (add_dnodeint(h, n));
	if (length == idx)
		return (add_dnodeint_end(h, n));
	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = node->prev = NULL;
	for (tmp = *h; tmp != NULL; tmp = tmp->next)
	{
		i++;
		if (i == idx)
		{
			node->next = tmp->next;
			node->prev = tmp;
			if (tmp->next)
				tmp->next->prev = node;
			tmp->next = node;
			return (node);
		}
	}
	return (NULL);
}
