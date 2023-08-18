#include "lists.h"

/**
 * sum_dlistint - get the sum of all nodes of list
 * @head: first node of dlistint list
 * Return: int
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;
	int sum = 0;

	if (head == NULL)
		return (sum);

	for (tmp = head; tmp != NULL; tmp = tmp->next)
		sum += tmp->n;

	return (sum);
}
