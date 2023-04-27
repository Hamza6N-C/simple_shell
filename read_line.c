#include "shell.h"
/**
 * read_line - Reads line from stdin
 * Return:  Pointer to the line read from stdin
 */
char *read_line(void)
{
	char *line = NULL;
	size_t size_of_buffer = 0;

	if (_getline(&line, &size_of_buffer, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			handle_error("read_line failed");
		}
	}
	return (line);
}

