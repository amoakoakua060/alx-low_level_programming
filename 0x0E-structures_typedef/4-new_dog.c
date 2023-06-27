#include "dog.h"

/**
 * _strlen - length of string
 * @a: string
 *
 * Description: this gets the length of a string
 *
 * Return: int
 */
int _strlen(char *a)
{
	int i = 0;

	while (a[i] != '\0')
		i++;

	return (i);
}
/**
 * _strcpy - copy string
 * @a: string
 * @b: string
 *
 * Description: copy from one string to another
 *
 * Return: void
 */
void _strcpy(char *a, char *b)
{
	int i;

	for (i = 0; b[i] != '\0'; i++)
		a[i] = b[i];

	a[i] = '\0';
}

/**
 * new_dog - create dog
 * @name: string
 * @age: float
 * @owner: string
 *
 * Description: create a new dog struct and initialize
 * with the values of name, age and owner variables
 *
 * Return: dog_t
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	d->name = NULL;
	d->owner = NULL;
	d->age = age;

	if (name != NULL)
	{
		d->name = malloc(sizeof(char) * (_strlen(name) + 1));
		if (d->name == NULL)
		{
			free(d);
			return (NULL);
		}
		_strcpy(d->name, name);
	}

	if (owner != NULL)
	{
		d->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
		if (d->owner == NULL)
		{
			free(d->name);
			free(d);
			return (NULL);
		}
		_strcpy(d->owner, owner);
	}
	return (d);
}
