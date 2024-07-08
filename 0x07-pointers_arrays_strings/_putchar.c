#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdo
 * @c: the character to be printed
 *
 * Return: 1 when it is successful
 * on error, -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
