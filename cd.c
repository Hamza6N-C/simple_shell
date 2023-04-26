#include <stdio.h>
#include "shell.h"

/**
 * cd_command - It handles the built-in command to change the current working directory
 * @path: Path of the directory
 * Return: 0
 */
void cd_command(char *path)
{
	int bac;

	if (path == NULL)
		path = getenv("HOME");
	bac = chdir(path);
	if (bac == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
}
