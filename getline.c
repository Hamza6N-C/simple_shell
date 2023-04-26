#include <stdio.h>
#include "shell.h"

/**
 * get_line - Reads the user input
 *
 * Return: Input
 */
char *get_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return (line);
}
