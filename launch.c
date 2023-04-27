#include "shell.h"
/**
 *launch - Launches a new process to execute given cmd.
 *@args: A '\0' array of strings representing cmd and its args
 *Return: 1 on success, or -1 on failure
 */
int launch(char **args)
{
	char **environ = NULL;
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{    /*child process*/
		char *path = getenv("PATH");
		char *dir = strtok(path, ":");

		while (dir != NULL)
		{
			char *command_path = malloc(strlen(dir) + strlen(args[0]) + 2);

			sprintf(command_path, "%s/%s", dir, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				args[0] = command_path;
				break;
			}
			free(command_path);
			dir = strtok(NULL, ":");
		}
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");/*fork error*/
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

