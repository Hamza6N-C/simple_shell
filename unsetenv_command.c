#include "shell.h"

/**
 * unsetenv_command - implement unsetenv command
 * @args: arguments
 * Return: 0 on success, or 1 on failure.
*/

int unsetenv_command(char **args)
{
	if (args[1] == NULL)
	{
		perror("unsetenv");
		return (1);
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
}
