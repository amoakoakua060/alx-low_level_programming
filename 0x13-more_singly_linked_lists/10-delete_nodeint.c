#include "lists.h"

/**
 * delete_nodeint_at_index - delete node at index
 * @head: pointer to first listint_t node
 * @index: index to delete
 * Return: int
 */
int delete_nodeint_at_index(
	listint_t **head, unsigned int index
)
{
	listint_t *tmp, *tmp2 = NULL;
	unsigned int i = 0;

	tmp = *head;
	while (tmp != NULL)
	{
		if (!tmp && i == 0 && i == index)
		{
			free(*head);
			return (1);
		}
		if (tmp && i == 0 && i == index)
		{
			*head = tmp->next;
			free(tmp);
			return (1);
		}
		if (i + 1 == index)
		{
			tmp2 = tmp->next;
			if (tmp->next)
				tmp->next = tmp2->next;
			free(tmp2);
			return (1);
		}
		if (tmp == NULL)
			return (-1);
		i++;
		tmp = tmp->next;
	}

	return (-1);
}
