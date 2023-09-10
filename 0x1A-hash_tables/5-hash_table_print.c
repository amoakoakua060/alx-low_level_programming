#include "hash_tables.h"

/**
* print_node - print key value pair
* @node: hash_node_t pointer
* @printed: integer (0 or 1)
*/
void print_node(hash_node_t *node, int printed)
{
	if (printed)
		printf(", ");
	printf("'%s': '%s'", node->key, node->value);
}

/**
* print_node_list - print linked list from head
* @head: hash_node_t pointer
* @printed: integer (0 or 1)
*/
void print_node_list(hash_node_t *head, int *printed)
{
	while (head != NULL)
	{
		print_node(head, *printed);
		*printed = 1;
		head = head->next;
	}
}

/**
* hash_table_print - print the key/value pairs of the hash table
* @ht: hash table
*/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *head;
	int printed = 0;

	if (ht == NULL)
		return;

	printf("{");

	while (i < ht->size)
	{
		head = ht->array[i];
		if (head && head->next == NULL)
		{
			print_node(head, printed);
			printed = 1;
			head  = head->next;
		}
		else if (head && head->next)
			print_node_list(head, &printed);

		i++;
	}

	printf("}\n");
}
