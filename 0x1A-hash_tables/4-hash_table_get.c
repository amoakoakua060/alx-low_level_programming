#include "hash_tables.h"

/**
* hash_table_get - get value associated with key
* @ht: hash table
* @key: string
*
* Return: char *
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *tmp;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	idx = key_index((const unsigned char *) key, ht->size);
	tmp = ht->array[idx];

	for (; tmp; tmp = tmp->next)
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);

	return (NULL);
}
