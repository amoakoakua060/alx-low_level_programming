#include "lists.h"

/**
 * sum_listint - sum nodes' n
 * @head: first listint_t node
 * Return: int
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
