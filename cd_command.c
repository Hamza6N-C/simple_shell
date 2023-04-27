#include "shell.h"
/**
 * cd_command - change the current working directory
 * @args: the arguments passed to shell
 * Return: 1 on sucess, 0 on failure
 */
int cd_command(char **args)
{
	char *new_directory = getcwd(NULL, 0);
	char *prev_directory = getenv("OLDPWD");

	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd");
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (prev_directory == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
		}
		else
		{
			if (chdir(prev_directory) != 0)
			{
				perror("cd");
			}
			printf("%s\n", prev_directory);
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
	if (new_directory == NULL)
	{
		handle_error("getcwd failed");
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", new_directory, 1);
	free(new_directory);
	return (1);
}
