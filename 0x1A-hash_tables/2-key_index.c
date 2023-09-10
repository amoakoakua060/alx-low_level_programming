#include "hash_tables.h"

/**
* key_index - find index using key
* @key: string
* @size: size of the hash table array
*
* Return: unsigned long int
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
