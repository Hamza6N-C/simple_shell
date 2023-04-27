#include "shell.h"

/**
 * setenv_command - implement setenv command
 * @args: arguments.
 * Return: Nothing
*/

void setenv_command(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		perror("setenv");
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return;
	}

}
