#include <stdio.h>
#include "shell.h"

/**
 * execute_command - Execute command with the specified arguements
 * @command: Command to be executed
 * @args: Arguments passed to the command
 * @env_var: Enviroment variable
 * Return: 0
 */
void execute_command(char *command, char **args, char **env_var)
{
	char *commandexecute;
	int status;
	pid_t pid;

	commandexecute = get_path_of_command(command);
	if (commandexecute == NULL)
	{
		printf("Command not found\n");
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(commandexecute, args, env_var) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
		}
		free(commandexecute);
	}
}

