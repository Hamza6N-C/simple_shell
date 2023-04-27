#include "shell.h"

/**
 * setenv_command - implement setenv command
 * @args: arguments.
 * Return: 0 on success, or 1 on failure.
*/

int setenv_command(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		perror("setenv");
		return (1);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}
