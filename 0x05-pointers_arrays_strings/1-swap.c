#include "main.h"
/**
* swap_int - swaps values of two integers
* @a: integer to swap
* @b: another integer to swap
*/
void swap_int(int *a, int *b)
{
	int m;

	m = *a;
	*a = *b;
	*b = m;
}
