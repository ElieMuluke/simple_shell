#include "simple_shell.h"

/**
 * _strcpy - Copies a string from source to destination
 * @source: The source string
 * @dest: The destination string
 *
 * Return: A pointer to the destination string
 */
char *_strcpy(char *dest, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _isalpha - Checks if the input character is an alphabetic letter
 * @c: The character to be checked
 *
 * Return: 1 if the character is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (SUCCESS);
	}
	return (FAIL);
}
