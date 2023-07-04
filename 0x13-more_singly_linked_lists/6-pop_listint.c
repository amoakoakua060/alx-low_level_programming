#include "lists.h"

/**
 * pop_listint - popping a node
 * @head: pointer to first listint_t node
 * Return: int
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n = 0;

	tmp = *head;
	if (tmp == NULL)
		return (n);

	*head = tmp->next;
	tmp->next = NULL;
	n = tmp->n;
	free(tmp);

	return (n);
}
