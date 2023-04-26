#include <stdio.h>
#include "shell.h"

/**
 * parse_command - It seperates the input input_command into two parts
 * @input: Command
 * Return: Arguments
 */
char *parse_command(char *input)
{
	char *input_command = strdup(input);
	char *space = strchr(input_command, ' ');

	if (space != NULL)
		*space = '\0';
	return (input_command);
}
