/**
* hash_djb2 - hashing algorithm
* @str: string
*
* Description: uses djb2 algorithm to hash strings
*
* Return: unsigned long int
*/
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
