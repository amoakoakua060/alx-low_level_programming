i#include "dog.h"

/**
 * print_dog - print dog_t
 * @d: struct dog pointer
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf(
		"Name: %s\nAge: %f\nOwner: %s\n",
		d->name ? d->name : "(nil)",
		d->age,
		d->owner ? d->owner : "(nil)"
	);
}
