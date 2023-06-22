#include <stdio.h>
/**
 * main - Entry point
 * Description: 'Program that prints numbers from o to 10 using putchar'
 * Return: Always 0
 */
int main(void)
{
	int n;

	for (n = 0 ; n < 10 ; n++)
	{
		printf("%d", n);
	}
	putchar('\n');
	return (0);
}
