#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - Prints name using pointer to function
 * @name: String to add
 * @f: Pointer to Function
 * Return: nothing
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
