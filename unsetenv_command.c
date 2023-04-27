#include "shell.h"
/**
 * unsetenv_command - function to unset enviroment variable
 * @args: array of arguments passed to shell
 * Return: 0 on success, 1 on failure
 */

int unsetenv_command(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "unsetenv: missing argument\n");
		return (1);
	}
	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
}
