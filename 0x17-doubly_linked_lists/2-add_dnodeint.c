#include "lists.h"

/**
 * add_dnodeint - add a new node with value n to the dlistint_t list
 * @head: pointer to first node of a dlistint list
 * @n: n value of the new node to be created
 * Return: dlistint_t
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = NULL;
	node->next = NULL;
	if (*head != NULL)
	{
		node->next = *head;
		(*head)->prev = node;
	}
	*head = node;
	return (node);
}
