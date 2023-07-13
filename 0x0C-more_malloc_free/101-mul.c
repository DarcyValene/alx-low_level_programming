#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _isdigit - Checks if a character is a digit (0 through 9)
 * @c: The character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Computes the length of a string
 * @s: The string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * _multiply - Multiplies a number represented as a string by a digit
 * @num: The number represented as a string
 * @digit: The digit to multiply by
 * @result: The resulting string to store the multiplication
 * @result_size: The size of the result string
 * @result_offset: The offset to start storing the result
 *
 * Return: The carry value (0 or 1)
 */
int _multiply(char *num, int digit, char *result, int result_size, int result_offset)
{
	int carry = 0;
	int i, prod;

	for (i = result_size - 1; i >= 0; i--)
	{
		prod = (num[i] - '0') * digit + carry;
		carry = prod / 10;
		result[i + result_offset] = (prod % 10) + '0';
	}

	return (carry);
}

/**
 * _add - Adds two numbers represented as strings
 * @num1: The first number represented as a string
 * @num2: The second number represented as a string
 * @sum: The resulting string to store the addition
 * @sum_size: The size of the sum string
 *
 * Return: The carry value (0 or 1)
 */
int _add(char *num1, char *num2, char *sum, int sum_size)
{
	int carry = 0;
	int i, n1, n2, digit_sum;

	for (i = sum_size - 1; i >= 0; i--)
	{
		n1 = (num1[i] != '\0') ? (num1[i] - '0') : 0;
		n2 = (num2[i] != '\0') ? (num2[i] - '0') : 0;
		digit_sum = n1 + n2 + carry;
		carry = digit_sum / 10;
		sum[i] = (digit_sum % 10) + '0';
	}

	return (carry);
}

/**
 * mul - Multiplies two positive numbers
 * @num1: The first number represented as a string
 * @num2: The second number represented as a string
 *
 * Return: The result of the multiplication as a string
 */
char *mul(char *num1, char *num2)
{
	int len1, len2, result_size, result_offset;
	char *result, *temp;
	int i, j, carry;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result_size = len1 + len2;
	result = malloc(sizeof(char) * (result_size + 1));

	if (result == NULL)
		return (NULL);

	for (i = 0; i < result_size; i++)
		result[i] = '0';

	result[result_size] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		result_offset = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			temp = malloc(sizeof(char) * (result_size + 1));

			if (temp == NULL)
			{
				free(result);
				return (NULL);
			}

			carry = _multiply(num2, (num1[i] - '0'), temp, result_size, result_offset) + carry;
			carry += _add(result, temp, result, result_size);
			result_offset++;
			free(temp);
		}

		if (carry > 0)
			result[result_offset] = carry + '0';
	}

	return (result);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: The command-line arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!_isdigit(*argv[1]) || !_isdigit(*argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	result = mul(argv[1], argv[2]);
	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}

	printf("%s\n", result);
	free(result);

	return (0);
}
