#include "shell.h"
/**
 * file_input - it reads a file and then execute the commands
 * @file_name: The name of the file to read
 * Return: 0 on success, 1 on failure
 */

int file_input(char *file_name)
{
	FILE *fp = fopen(file_name, "r");
	char *line = NULL;
	size_t buffer_size = 0;
	int status = 0;

	if (fp == NULL)
	{
		perror("file_input");
		return (1);
	}

	while (_getline(&line, &buffer_size, fp) != -1)
	{
		char **args = parse_line(line);

		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				status = exit_command(args);

			}
			else
			{
				status = commad_execute(args);
			}
		}
		free(args);
		if (status != 0)
		{
			break;
		}
	}
	free(line);
	fclose(fp);
	return (status);
}
