#include "simple_shell.h"
/**
 * _atoi - Convert a string to an integer
 * @str: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *str)
{
	unsigned int val = 0;
	int sign = 1;

	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		else
			val = (val * 10) + (*str - '0');
		str++;
	}
	return (sign * val);
}

/**
 * intlen - Calculate the number of digits in an integer
 * @num: The integer to calculate the length of
 *
 * Return: The length of the integer
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * print_error - Print an error message
 * @data: A pointer to the data structure
 *
 * Return: Always returns 0
 */
int print_error(sh_t *data)
{
	char idx[BUFSIZE];
	sprintf(idx, "%lu", data->index);

	PRINT("hsh: ");
	PRINT(idx);
	PRINT(": ");
	PRINT(data->args[0]);
	PRINT(": ");
	PRINT(data->error_msg);
	return (0);
}
/**
 * write_history - Write a line of history to a file
 * @data: A pointer to the data structure (unused)
 *
 * Return: 1 on success, -1 on failure
 */
int write_history(sh_t *data __attribute__((unused)))
{
	char *filename = "history";
	char *line_of_history = "this is a line of history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (line_of_history)
	{
		while (line_of_history[len])
			len++;
		w = write(fd, line_of_history, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
