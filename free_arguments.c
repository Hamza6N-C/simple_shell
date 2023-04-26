#include <stdio.h>
#include "shell.h"

/**
 * free_arguments - Frees the memory for a list of arguments in it
 * @args: List of arguments
 * Return: 0
 */
void free_arguments(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i++]);
	}
	free(args);
}

