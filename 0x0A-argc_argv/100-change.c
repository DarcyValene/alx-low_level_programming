#include <stdio.h>
#include <stdlib.h>

/**
 * get_min_coins - Calculates the minimum number of coins needed for change
 * @cents: The amount of cents to make change for
 *
 * Return: The minimum number of coins
 */
int get_min_coins(int cents)
{
	int coins = 0;

	if (cents >= 25)
	{
		cents -= 25;
	}
	else if (cents >= 10)
	{
		cents -= 10;
	}
	else if (cents >= 5)
	{
		cents -= 5;
	}
	else if (cents >= 2)
	{
		cents -= 2;
	}
	else
	{
		cents -= 1;
	}

	coins++;

	return (coins);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 if successful, 1 if there are invalid arguments
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	while (cents > 0)
	{
		coins += get_min_coins(cents);
	}

	printf("%d\n", coins);
	return (0);
}
