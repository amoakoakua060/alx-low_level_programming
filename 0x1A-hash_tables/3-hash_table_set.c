#include "hash_tables.h"

/**
* create_hash_node - create a new hash_node_t node
* @node: pointer to hash_node_t
* @key: string
* @value: string
*
* Return: int
*/
int create_hash_node(
	hash_node_t **node, const char *key, const char *value
)
{
	(*node) = malloc(sizeof(hash_node_t));
	if (*node == NULL)
		return (0);

	(*node)->key = strdup(key);
	(*node)->value = NULL;
	(*node)->next = NULL;
	if (value)
	{
		(*node)->value = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy((*node)->value, value);
	}

	return (1);
}

/**
* resolve_collision - resolve collision during set of node
* @head: head of hash_node_t linked list
* @node: pointer to hash_node_t
* @key: string
* @value: string
*
* Return: int
*/
int resolve_collision(
	hash_node_t **head, hash_node_t **node,
	const char *key, const char *value
)
{
	hash_node_t *tmp = *head;
	int result;

	for (; tmp; tmp = tmp->next)
		if (strcmp(tmp->key, key) == 0)
		{
			if (tmp->value)
				free(tmp->value);

			if (value)
			{
				tmp->value = malloc(
					sizeof(char) * (strlen(value) + 1));
				strcpy(tmp->value, value);
			}
			else
				tmp->value = NULL;

			return (1);
		}

	result = create_hash_node(node, key, value);
	if (!result)
		return (0);

	(*node)->next = *head;

	return (1);
}

/**
* hash_table_set - set the key-value pair in the hash table
* @ht: hash table
* @key: string
* @value: string
*
* Return: int
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *head = NULL, *node = NULL;
	unsigned long int idx;
	int res = 1;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (0);

	idx = key_index((const unsigned char *) key, ht->size);
	head = ht->array[idx];

	if (head == NULL)
		res = create_hash_node(&node, key, value);
	else
		res = resolve_collision(&head, &node, key, value);

	if (!res)
		return (0);

	if (node)
		ht->array[idx] = node;

	return (1);
}
