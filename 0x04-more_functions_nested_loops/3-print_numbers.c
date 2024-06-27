#include "main.h"

/**
 * print_numbers - print numbers in a new line
 *
 * Return: always 0
 */
void print_numbers(void)
{
	int c;

	for (c = 48; c < 58; c++)
	{
		_putchar(c);
	}
_putchar('\n');
}
