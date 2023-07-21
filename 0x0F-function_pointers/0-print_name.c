#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - Prints a name.
 * @name: Pointer to the name to be printed.
 * @f: Pointer to the function to use for printing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
