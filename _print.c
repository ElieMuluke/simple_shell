#include "main.h"

/**
 * _printchar - this function writes characters to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_arguments - this function prints the arguments passed to the program
 * @argv: the arguments passed to the program
 * @argc: the number of arguments passed to the program
 *
 * Return: void
 */
void print_arguments(char *argv[], int argc)
{
	int i, j;

	for (i = 0; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			_printchar(argv[i][j]);
		}
		_printchar('\n');
	}
}

/**
 * print_str - this function prints a string
 * @str: the string to print
 *
 * Return: void
 */
void print_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_printchar(str[i]);
	}
	_printchar('\n');
}
