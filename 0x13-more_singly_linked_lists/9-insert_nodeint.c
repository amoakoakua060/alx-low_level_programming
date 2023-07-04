#include "lists.h"

/**
 * insert_nodeint_at_index - insert
 * @head: pointer to first listint_t node
 * @idx: index to insert at
 * @n: int n of the new node
 *
 * Description: remove head node of list
 *
 * Return: int
 */
listint_t *insert_nodeint_at_index(
	listint_t **head, unsigned int idx, int n
)
{
	listint_t *tmp, *n_node;
	unsigned int i = 0;

	tmp = *head;
	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
		return (NULL);
	n_node->n = n;
	n_node->next = NULL;
	while (i != idx)
	{
		if (!tmp && i == 0 && i == idx)
		{
			*head = n_node;
			return (n_node);
		}
		if (tmp && i == 0 && i == idx)
		{
			n_node->next = tmp;
			*head = n_node;
			return (n_node);
		}
		if (i + 1 == idx)
		{
			n_node->next = tmp->next;
			tmp->next = n_node;
			return (n_node);
		}
		if (tmp == NULL)
		{
			free(n_node);
			return (NULL);
		}
		i++;
		tmp = tmp->next;
	}
	free(n_node);
	return (NULL);
}
