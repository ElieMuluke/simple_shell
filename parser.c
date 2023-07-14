#include "simple_shell.h"

/**
 * is_path_form - checks if the given filename represents a path
 * @data: a pointer to the data structure
 *
 * Return: (Success) 1 if the command is a path, 0 otherwise
 * ------- (Fail) -
 */
int is_path_form(sh_t *data)
{
	if (_strchr(data->args[0], '/') != 0)
	{
		data->cmd = _strdup(data->args[0]);
		return 1;  /* Path form */
	}
	return 0;  /* Not a path form */
}

#define DELIMITER ":"

/**
 * is_short_form - checks if the given filename is in short form
 * @data: a pointer to the data structure
 *
 * Return: (Success) -
 * ------- (Fail) -
 */
void is_short_form(sh_t *data)
{
	char *path, *token, *_path;
	struct stat st;
	int exist_flag = 0;

	path = _getenv("PATH");
	_path = _strdup(path);
	token = strtok(_path, DELIMITER);
	while (token)
	{
		data->cmd = _strcat(token, data->args[0]);
		if (stat(data->cmd, &st) == 0)
		{
			exist_flag += 1;
			break;
		}
		free(data->cmd);
		token = strtok(NULL, DELIMITER);
	}
	if (exist_flag == 0)
	{
		data->cmd = _strdup(data->args[0]);
	}
	free(_path);
}

#undef DELIMITER

/**
 * is_builtin - checks if the command is a built-in command
 * @data: a pointer to the data structure
 *
 * Return: (Success) 1 if the command is a built-in command, 0 otherwise
 * ------- (Fail) -
 */
int is_builtin(sh_t *data)
{
	blt_t blt[] = {
		{"exit", abort_prg},
		{"cd", change_dir},
		{"help", display_help},
		{NULL, NULL}
	};
	int i = 0;

	while ((blt + i)->cmd)
	{
		if (_strcmp(data->args[0], (blt + i)->cmd) == 0)
			return 1;  /* Built-in command */
		i++;
	}
	return 0;  /* Not a built-in command */
}
