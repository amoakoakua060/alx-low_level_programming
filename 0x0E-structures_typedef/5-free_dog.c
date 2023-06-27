#include "dog.h"

/**
 * free_dog - free struct dog
 * @d: struct dog pointer
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	if (d->owner)
		free(d->owner);

	if (d->name)
		free(d->name);

	free(d);
}
