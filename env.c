#include <stdio.h>
#include "shell.h"

/**
 * env_command - Prints the env variables
 * @envp: Pointer to an array
 * Return: 0
 */
void env_command(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		printf("%s\n", envp[i++]);
	}
}
