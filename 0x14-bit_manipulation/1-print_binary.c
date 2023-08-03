#include "main.h"

/**
 * get_bit - Returns the value of a bit at a specific index in a decimal number.
 * @n: The decimal number to search.
 * @index: The index of the bit (0-based) to retrieve.
 *
 * Return: The value of the bit at the given index, or -1 if the index is invalid.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* Variable to store the value of the bit at the given index. */
	int bit_val;

	/* Check if the index is greater than 63 (the number of bits in an unsigned long int).
	 * If it is, the index is invalid, so return -1. */
	if (index > 63)
		return (-1);

	/* Shift the decimal number to the right by 'index' positions and then extract the least significant bit.
	 * This will give us the value of the bit at the specified index. */
	bit_val = (n >> index) & 1;

	/* Return the value of the bit at the given index. */
	return (bit_val);
}
