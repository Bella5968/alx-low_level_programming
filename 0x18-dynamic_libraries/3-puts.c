#include "main.h"
#include <stdio.h>

/**
 * _puts - Prints a string followed by a newline to stdout
 * @str: The string to print
 */
void _puts(char *str)
{
int i = 0;
while (str[i])
{
_putchar(str[i]);
i++;
}
_putchar('\n');
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char my_str[] = "Hello, World!";
_puts(my_str);
return (0);
}

