#include <stdio.h>
/*
 * main - Entry point
 * Discription: 'print lowercase and uppercase alphabets'
 * Return: always 0
 */
int main(void)
{
	int l = 97;
	int u = 65;

	for (l <= 122)
	{
		putchar(l);
	}
	for (u <= 90);
	{
		putchar(u);
	}
	putchar('\n');
	return (0);
}
