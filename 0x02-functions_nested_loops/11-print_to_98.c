#include "main.h"

#include <stdio.h>

/**
 * print_to_98 - prints all natural number for n to 98
 * @n: the number start printing from
 * Return: Always 0.
 */

void print_to_98(int n)

{
	if (n <= 98)
	{
	for (; n <= 98; n++)
	{
	if (n == 98)
	{
	printf("%d, ", n);
	printf("\n");
	break;
	}
	else
	{
		printf("%d, ", n);
	}
	}
	}
}

