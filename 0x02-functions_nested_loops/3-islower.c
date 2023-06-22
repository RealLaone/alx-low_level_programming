#include "main.h"
/**
* islower - check if char is lowercase
* @c: is char in ASCII
* Return: 1 if char is lowercase, otherwise 0.
*/
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
