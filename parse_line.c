#include "shell.h"
/**
 *parse_line - Parses a line of input into an array of tokens.
 *@line: The line of input to be parsed.
 *Return: An array of tokens, or NULL if there was an error.
 */

char **parse_line(char *line)
{
	int size_of_buffer = BUFFER_SIZE;
	int pos = 0;
	char **tokens = malloc(size_of_buffer * sizeof(char *));
	char *token;

	if (!tokens)
	{
		handle_error("parse_line failed: allocation error");
	}
	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[pos] = token;
		pos++;
		if (pos >= size_of_buffer)
		{
			size_of_buffer += BUFFER_SIZE;
			tokens = realloc(tokens, size_of_buffer * sizeof(char *));
			if (!tokens)
			{
				handle_error("parse_line failed: allocation error");
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[pos] = NULL;
	return (tokens);
}
