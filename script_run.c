#include "shell.h"
/**
 * run_script - run a script from a given file
 * @file_name: the name of the file to be read
 * Return: 0 on sucess, 1 on failure
 */

int run_script(char *file_name)
{
	FILE *fp = fopen(file_name, "r");
	char *line = NULL;
	size_t buffer_size = 0;

	if (fp == NULL)
	{
		perror("run_script");
		return (1);
	}

	while (_getline(&line, &buffer_size, fp) != -1)
	{
		char **args = parse_line(line);

		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exit_command(args);
			}
			else
			{
				commad_execute(args);
			}
		}
		free(args);
	}
	free(line);
	fclose(fp);
	return (0);
}
