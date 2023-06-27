#include "dog.h"

/**
 * init_dog - initialize struct dog
 * @d: struct dog pointer
 * @name: string
 * @age: float
 * @owner: string
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(dog_t));

	d->name = name;
	d->owner = owner;
	d->age = age;
}
