#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if invalid input
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_val = 0;
	unsigned int bit_value = 1;
	int i;

	if (!b)
		return (0);


	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		bit_value = 1;
		for (int j = 0; j < (i - 1); j++)
		bit_value *= 2;

		dec_val += (b[i] - '0') * bit_value;
	}

	return (dec_val);
}
