#include "shell.h"
/**
 * hundle_alias - Implements the alias builtin command
 * @args: An array of strings containing the command and its arguments
 * Return: Always returns 0
 */
int hundle_alias(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		char *msg_error = "alias: missing arguments\n";

		write(STDERR_FILENO, msg_error, strlen(msg_error));
		return (1);
	}

	return (0);
}
