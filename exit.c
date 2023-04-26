#include <stdio.h>
#include "shell.h"

/**
 * handle_the_exit - This exits the shell
 * @args: The command line arguments
 * Return: 0
 */
int handle_the_exit(char **args)
{
	int i = 0, status = 0;

	if (args[i])
		status = atoi(args[1]);
	free_args(args);
	exit(status);
}
