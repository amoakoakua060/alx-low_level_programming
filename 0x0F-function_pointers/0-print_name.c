#include "function_pointers.h"

/**
 * print_name - print string using f
 * @name: string
 * @f: function pointer
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
