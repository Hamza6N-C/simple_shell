#include <stdio.h>
#include "shell.h"

/**
 * get_path_of_command - This takes command as an arguement
 * @command: Name of the command
 * Return: PATH
 */
char *get_path_of_command(char *command)
{
	char *env_path = getenv("PATH");
	char *dir;
	char *path;
	char *path_of_command = NULL;

	path = strtok(env_path, ":");
	while (path != NULL)
	{
		dir = malloc(strlen(path) + strlen(command) + 2);
		if (!dir)
		{
			perror("memory error");
			exit(EXIT_FAILURE);
		}
		sprintf(dir, "%s/%s", path, command);
		if (access(dir, X_OK) == 0)
		{
			path_of_command = dir;
			break;
		}
		else
		{
			free(dir);
		}
		path = strtok(NULL, ":");
	}
	return (path_of_command);
}
