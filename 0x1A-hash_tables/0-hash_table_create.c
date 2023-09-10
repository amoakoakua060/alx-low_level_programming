#include "hash_tables.h"

/**
* hash_table_create - create a hash table
* @size: the size of the created hash table
*
* Return: hash_table *
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int a = 0;
	hash_table_t *hash_t = NULL;

	if (size == 0)
		return (NULL);

	hash_t = malloc(sizeof(hash_table_t));
	if (hash_t == NULL)
		return (NULL);

	hash_t->size = size;
	hash_t->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_t->array == NULL)
	{
		free(hash_t);
		return (NULL);
	}

	while (a < size)
	{
		hash_t->array[a] = NULL;
		a++;
	}

	return (hash_t);
}
