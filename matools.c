#include "simple_shell.h"
/**
 * _strcat - Concatenates two strings in a path format.
 * @first: The destination string.
 * @second: The source string.
 *
 * Return: (Success) returns a pointer to the newly concatenated string.
 * ------- (Fail) returns NULL if concatenation failed.
 */
char *_strcat(char *first, char *second)
{
	int len1, len2, i = 0, j = 0;
	char *result;

	len1 = _strlen(first);
	len2 = _strlen(second);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (first[j])
		result[i++] = first[j++];
	result[i++] = '/';
	j = 0;
	while (second[j])
		result[i++] = second[j++];
	result[i] = '\0';
	return (result);
}

/**
 * _strlen - Determines the length of a given string.
 * @str: The string to calculate the length of.
 *
 * Return: (Success) The length of the string is returned.
 * ------- (Fail) A negative value is returned.
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: (Success) A positive number is returned if strings are different.
 * ------- (Fail) A negative number is returned if strings are the same.
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @str: The string to search in.
 * @c: The character to find.
 *
 * Return: (Success) return A pointer to the first occurrence of the character.
 * ------- (Fail) NULL is returned if the character is not found
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return (ptr);
	return (NULL);
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: (Success) A pointer to the duplicated string is returned.
 * ------- (Fail) NULL is returned if duplication failed.
 */
char *_strdup(char *str)
{
	char *dupl;

	if (str == NULL)
		return (NULL);
	dupl = malloc(_strlen(str) + 1);
	if (dupl == NULL)
		return (NULL);
	_strcpy(dupl, str);
	return (dupl);
}
