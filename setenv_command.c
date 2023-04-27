#include "shell.h"
/**
 *setenv_command - Set environment variable.
 *@args: Array of strings containing the cmd and its args.
 *Return: 0 on success, or 1 on failure.
 */
int setenv_command(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "setenv: missing arguments\n");
		return (1);
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}
