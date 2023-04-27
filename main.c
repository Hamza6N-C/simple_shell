#include "shell.h"
/**
 * main - main fuction
 * line: stores the command entered by user
 * args: stores the parsed command
 * @argc: argument count
 * @argv: argument vector
 * status: stores the status of executed command
 * Return: Success
 */

int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	if (argc > 1)
	{
		file_input(argv[1]);
		return (EXIT_SUCCESS);
	}
	do {
		prompt();
		line = read_line();
		args = parse_line(line);
		status = commad_execute(args);
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
