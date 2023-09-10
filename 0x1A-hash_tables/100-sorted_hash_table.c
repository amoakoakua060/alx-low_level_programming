#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: shash_table_t *
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i = 0;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	while (i < size)
	{
		ht->array[i] = NULL;
		i++;
	}

	return (ht);
}

/**
* create_shash_node - create the shash node
* @node: pointer to node to be created
* @key: string
* @value: string
*/
void create_shash_node(shash_node_t **node, const char *key, const char *value)
{
	(*node) = malloc(sizeof(shash_node_t));
	if ((*node) == NULL)
		return;
	(*node)->key = strdup(key);
	(*node)->value = strdup(value);
	(*node)->sprev = NULL;
	(*node)->snext = NULL;
}

/**
 * shash_table_set - adds element to a sorted hash table.
 * @ht: hash table.
 * @key: string
 * @value: string
 *
 * Return: int
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	for (; tmp; tmp = tmp->snext)
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
	create_shash_node(&new_node, key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	if (ht->shead == NULL)
		ht->shead = ht->stail = new_node;
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->snext = ht->shead;
		ht->shead = ht->shead->sprev = new_node;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new_node->sprev = tmp;
		new_node->snext = tmp->snext;
		if (tmp->snext)
			tmp->snext->sprev = new_node;
		else
			ht->stail = new_node;
		tmp->snext = new_node;
	}
	return (1);
}

/**
 * shash_table_get - get the value associated with key
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: char *
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->snext;
	}

	return (NULL);
}

/**
 * shash_table_print - prints sorted hash table
 * @ht: sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted hash table in reverse order.
 * @ht: sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes sorted hash table
 * @ht: sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}

	free(head->array);
	free(head);
}
