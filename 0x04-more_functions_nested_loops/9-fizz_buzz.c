#include <stdio.h>
/**
 * main - prints the number from 1 to 100 for multiples of 3
 * Fizz is printed instead of the numb for multiple of five
 * Buzz for multiples of both 3 and 5 FizzBuzz
 *
 * Return: always 0
 */
int main(void)
{
int num;
for (num = 1; num <= 100; num++)
{
if ((num % 3) == 0 && (num % 5) == 0)
printf("FizzBuzz");
else if ((num % 3) == 0)
printf("Fizz");
else if ((num % 5) == 0)
printf("Buzz");
else
printf("%d", num);
if (num == 100)
continue;
printf(" ");
}
printf("\n");
return (0);
}
