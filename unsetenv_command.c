#include "shell.h"

/**
 * unsetenv_command - implement unsetenv command
 * @args: arguments
 * Return: Nothing
*/

void unsetenv_command(char **args)
{
	if (args[1] == NULL)
	{
		perror("unsetenv");
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return;
	}
}
