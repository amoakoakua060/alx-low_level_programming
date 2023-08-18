#include "lists.h"

/**
 * add_dnodeint_end - add a new node with value n at the end of dlistint_t list
 * @head: pointer to first node of a dlistint list
 * @n: n value of the new node to be created
 * Return: dlistint_t *
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *tmp;

	if (head == NULL)
		return (NULL);

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	node->prev = tmp;
	tmp->next = node;
	return (node);
}
