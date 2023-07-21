#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_char - Print a character
 * @args: The va_list containing the character to print
 */
void print_char(va_list args)
{
	char c = va_arg(args, int);
	printf("%c", c);
}

/**
 * print_int - Print an integer
 * @args: The va_list containing the integer to print
 */
void print_int(va_list args)
{
	int num = va_arg(args, int);
	printf("%d", num);
}

/**
 * print_float - Print a float
 * @args: The va_list containing the float to print
 */
void print_float(va_list args)
{
	double num = va_arg(args, double);
	printf("%f", num);
}

/**
 * print_string - Print a string
 * @args: The va_list containing the string to print
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str)
		printf("%s", str);
	else
		printf("(nil)");
}

/**
 * print_all - Prints anything.
 * @format: A list of types of arguments passed to the function.
 * @...: Variable number of arguments (of any type).
 *
 * Return: void.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j = 0;
	char *separator = "";

	typedef struct print_function
	{
		char format;
		void (*printer)(va_list);
	} print_fn_t;

	print_fn_t print_functions[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (print_functions[j].format)
		{
			if (format[i] == print_functions[j].format)
			{
				printf("%s", separator);
				print_functions[j].printer(args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
