#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * main_errors_helper - error handler to prevent more than 40 line
 * @text: error message
 * @code: exit code
 * Return: Nothing.
*/
void main_errors_helper(char *text, int code)
{
	perror(text);
	exit(code);
}

/**
 * main - the program starts here.
 * @argc: argument length
 * @argv: arguments
 * Return: 0
*/
int main(int argc, char *argv[])
{
	char *prompt = "#cisfun$ ", *line, **args;
	int status = 1;

	(void)argc;

	do {
		if (!isatty(STDIN_FILENO))
			write(STDIN_FILENO, prompt, _strlen(prompt));

		line = _readline();
		if (line == NULL)
		{
			free(line);
			break;
		}

		args = parse_line(line);
		if (args[0] != NULL)
		{
			command_execution(args, argv);
			free(args);
		}
		free(line);
	} while (status);

	return (0);
}

