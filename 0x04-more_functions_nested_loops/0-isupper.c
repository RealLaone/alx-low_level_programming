#include "main.h"
/**
 * _isupper - checks for uppercase letters
 * @c: char to check
 *
 * Return: 1 if c is uppercase
 * Otherwise 0
 */
int _isupper(int c)
{

	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
