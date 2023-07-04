#include "lists.h"

/**
 * add_nodeint - add new node to list
 * @head: pointer to first listint_t node
 * @n: int n of new struct
 * Return: size_t
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *n_node;

	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
		return (NULL);

	n_node->next = *head;
	n_node->n = n;
	*head = n_node;

	return (n_node);
}
