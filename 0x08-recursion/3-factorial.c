#include "main.h"

/**
 * factorial - Calculates the factorial of a number.
 * @n: The number to calculate the factorial of.
 *
 * Return: The factorial of the number.
 */
int factorial(int n)
{
	if (n < 0) /* Base case: negative number */
		return (-1);
	else if (n == 0 || n == 1) /* Base case: 0 or 1 */
		return (1);
	else
		return (n * factorial(n - 1)); /* Recursively calculate factorial */
}
