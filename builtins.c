#include "simple_shell.h"

#define SET_OLDPWD(V) (V = _strdup(_getenv("OLDPWD")))

/**
 * change_directory - Changes the current directory
 * @data: A pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) A negative number is returned
 */
int change_directory(sh_t *data)
{
	char *home;

	home = _getenv("HOME");
	if (data->args[1] == NULL)
	{
		SET_OLDPWD(data->oldpwd);
		if (chdir(home) < 0)
			return (FAIL);
		return (SUCCESS);
	}
	if (_strcmp(data->args[1], "-") == 0)
	{
		if (data->oldpwd == 0)
		{
			SET_OLDPWD(data->oldpwd);
			if (chdir(home) < 0)
				return (FAIL);
		}
		else
		{
			SET_OLDPWD(data->oldpwd);
			if (chdir(data->oldpwd) < 0)
				return (FAIL);
		}
	}
	else
	{
		SET_OLDPWD(data->oldpwd);
		if (chdir(data->args[1]) < 0)
			return (FAIL);
	}
	return (SUCCESS);
}

#undef GETCWD

/**
 * exit_program - Exit the program
 * @data: A pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) A negative number is returned
 */
int exit_program(sh_t *data __attribute__((unused)))
{
	int code, i = 0;

	if (data->args[1] == NULL)
	{
		free_data(data);
		exit(errno);
	}
	while (data->args[1][i])
	{
		if (_isalpha(data->args[1][i++]) < 0)
		{
			data->error_msg = _strdup("Illegal number\n");
			return (FAIL);
		}
	}
	code = _atoi(data->args[1]);
	free_data(data);
	exit(code);
}

/**
 * display_help - Display the help menu
 * @data: A pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) A negative number is returned
 */
int display_help(sh_t *data)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(data->args[1], O_RDONLY);
	if (fd < 0)
	{
		data->error_msg = _strdup("No help topics match\n");
		return (FAIL);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			data->error_msg = _strdup("Cannot write: permission denied\n");
			return (FAIL);
		}
	}
	PRINT("\n");
	return (SUCCESS);
}

/**
 * handle_builtins - Handle and manage the built-in commands
 * @data: A pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) A negative number is returned
 */
int handle_builtins(sh_t *data)
{
	blt_t builtin_cmds[] = {
		{"exit", exit_program},
		{"cd", change_directory},
		{"help", display_help},
		{NULL, NULL}
	};
	int i = 0;

	while ((builtin_cmds + i)->cmd)
	{
		if (_strcmp(data->args[0], (builtin_cmds + i)->cmd) == 0)
			return ((builtin_cmds + i)->f(data));
		i++;
	}
	return (FAIL);
}
