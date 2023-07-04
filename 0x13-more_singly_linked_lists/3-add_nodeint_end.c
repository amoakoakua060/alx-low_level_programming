#include "lists.h"

/**
 * add_nodeint_end - add node to the end
 * @head: pointer to first listint_t node
 * @n: int n of new struct
 * Return: size_t
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *n_node;
	listint_t *tmp;

	n_node = malloc(sizeof(listint_t));
	if (head == NULL || n_node == NULL)
		return (NULL);

	n_node->n = n;
	n_node->next = NULL;

	if (*head == NULL)
	{
		*head = n_node;
		return (n_node);
	}

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = n_node;

	return (n_node);
}
