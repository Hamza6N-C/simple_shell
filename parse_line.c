#include "shell.h"

/**
 * parse_line - function that parses the line
 * @line: line given
 * Return: Tokens
 */
char **parse_line(char *line)
{
	int size_of_buffer = BUFFER_SIZE, place = 0;
	char **tokens = malloc(size_of_buffer * sizeof(char *)), *token;

	if (!tokens)
	{
		write(STDERR_FILENO, "Allocation error\n", _strlen("Allocation error\n"));
		exit(EXIT_FAILURE);
	}

	token = _strtok(line, TOKEN_DELIM);

	while (token != NULL)
	{
		tokens[place] = token;
		place++;

		if (place >= size_of_buffer)
		{
			size_of_buffer += BUFFER_SIZE;
			tokens = realloc(tokens, size_of_buffer * sizeof(char *));
			if (!tokens)
			{
				write(STDERR_FILENO, "Allocation error\n", _strlen("Allocation error\n"));
				exit(EXIT_FAILURE);
			}
		}

		token = _strtok(NULL, TOKEN_DELIM);
	}
	tokens[place] = NULL;

	return (tokens);
}

