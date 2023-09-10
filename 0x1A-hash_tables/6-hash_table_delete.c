#include "hash_tables.h"

/**
* hash_table_delete - delete hash table
* @ht: hash table
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *head, *tmp;

	if (ht == NULL)
		return;

	if (ht->array == NULL || ht->size == 0)
	{
		free(ht);
		return;
	}

	while (i < ht->size)
	{
		if (ht->array[i] == NULL)
		{
			i++;
			continue;
		}
		head = ht->array[i];
		while (head)
		{
			tmp = head;
			head = head->next;
			tmp->next = NULL;
			free(tmp->key);
			if (tmp->value)
				free(tmp->value);
			free(tmp);
			tmp = NULL;
		}
		ht->array[i] = NULL;
		i++;
	}
	free(ht->array);
	free(ht);
}
