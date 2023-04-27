#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_INPUT_LENGTH 1024

int split_args(char *input, char **args, int max_args);
char *my_getline(void);
void cd(char *dir);
void execute_command(char *args[]);

#include <stdio.h>
#include <stdlib.h>

char *my_getline()
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	size_t characters_read = 0;
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		if (characters_read == buffer_size)
		{
			buffer_size += 1024;
			buffer = realloc(buffer, buffer_size);
		}
		buffer[characters_read++] = c;
	}

	if (buffer != NULL)
	{
		buffer[characters_read] = '\0';
	}

	return (buffer);
}


void execute_command(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		printf("Error: Failed to fork (%s)\n", strerror(errno));
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printf("Error: Failed to execute command (%s)\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	} else
	{

		if (waitpid(pid, &status, 0) == -1)
		{
			printf("Error: Failed to wait for child process (%s)\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
}



int split_args(char *input, char **args, int max_args)
{
	int num_args = 0;

	while (*input != '\0' && num_args < max_args)
	{

		while (isspace(*input))
		{
			++input;
		}

		if (*input == '\0')
		{
			break;
		}

		args[num_args++] = input;

		while (*input != '\0' && !isspace(*input))
		{
			++input;
		}

		if (*input != '\0')
		{
			*input++ = '\0';
		}
	}

	args[num_args] = NULL;
	return (num_args);
}


void cd(char *dir)
{
	/* If no directory is specified, change to user's Home directory*/

	if (dir == NULL)
	{
		char *home = getenv("HOME");

		if (home == NULL)
		{
			printf("cd: Home directory not found\n");
			return;
		}
		dir = home;
	}
	/*chdir() to change directory */

	if (chdir(dir) == -1)
	{
		perror("cd");
	}
}

#endif

