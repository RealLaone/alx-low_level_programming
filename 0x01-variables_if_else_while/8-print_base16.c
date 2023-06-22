#include <stdio.h>
/**
 * main - Entry point
 * Description: 'Printing all numbers of base16 in lowercase'
 * Return: 0
 */
int main(void)
{
	int n;
	int a;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
	}
	for (a = 97; a <= 102; a++)
	{
		putchar(a);
	}
	putchar('\n');
	return (0);
}
