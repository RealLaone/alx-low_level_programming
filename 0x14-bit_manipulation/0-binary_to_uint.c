#include "main.h"

/**
 * bin_to_uint - converts a binary string to an unsigned int
 * @b: pointer to the binary string
 *
 * Return: the converted number or 0 if b is NULL or invalid
 */
unsigned int bin_to_uint(const char *b)
{
	unsigned int num = 0;

	if (!b) 
		return (0);

	while (*b) 
	{ 
		if (*b != ‘0’ && *b != ‘1’) 
			return (0); 
		num = (num << 1) | (*b - ‘0’); 
		b++; 
	}

	return (num);
}


