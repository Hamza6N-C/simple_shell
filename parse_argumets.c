#include <stdio.h>
#include "shell.h"

/**
 * parse_arguments - It tokenize the command line into an array of arguments
 * @line: Pointer to the command line string
 * Return: pointer of an array or arguments, otherwise NULL
 */
char **parse_arguments(char *line)
{
	int i = 0;
	char *token;
	char **arguments = malloc(MAX_ARGS * sizeof(char *));

	if (!arguments)
	{
		perror("Memory error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, "\n");
	while (token != NULL)
	{
		arguments[i++] = token;
		token = strtok(NULL, " \n");
	}
	arguments[i] = NULL;
	return (arguments);
}

