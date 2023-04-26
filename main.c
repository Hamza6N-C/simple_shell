#include "shell.h"

/**
 * main - this an entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	pid_t pid;
	int status;
	char *command = parse_command(input);
	char **arguments = parse_arguments(input);

	while (1)
	{
		printf("$ ");
		if (!fgets(input, MAX_INPUT_LENGTH, stdin))
			break;
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
			exit(0);

		if (command == NULL)
		{
			printf("The command is not valid\n");
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(command, arguments) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
		free(command);
		free_arguments(arguments);
	}
	return (0);
}
