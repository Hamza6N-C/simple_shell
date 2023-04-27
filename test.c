#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "header.h"


#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

int main(void)
{

	char *input;
	char *args[MAX_ARGS];
	int num_args;

	do {
		printf("my-shell$ ");

		input = my_getline();
		if (input == NULL)
		{
			printf("Exiting my-shell\n");
			exit(EXIT_SUCCESS);
		}

		if (strlen(input) <= 1 || input[0] == '\n')
		{
			free(input);
			continue;
		}

		num_args = 0;
		args[num_args] = strtok(input, " \t\n");
		while (args[num_args] != NULL && num_args < MAX_ARGS - 1)
		{
			num_args++;
			args[num_args] = strtok(NULL, " \t\n");
		}
		args[num_args] = NULL;
		if (num_args == 0)
		{
			free(input);
			continue;
		}

	/* calling the cd command */

	if (strcmp(args[0], "cd") == 0)
	{
		cd(args[1]);
		continue;
	}

		if (strcmp(args[0], "exit") == 0)
		{
			free(input);
			break;
		}

		execute_command(args);

		free(input);
	} while (1);

	printf("Exiting my-shell\n");
	exit(EXIT_SUCCESS);
}
