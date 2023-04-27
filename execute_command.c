#include "shell.h"
#include <stdio.h>

static our_command our_commands[6] = {
	{"cd", hundle_cd},
	{"env", hundle_env},
	{"echo", hundle_echo},
	{"setenv", hundle_setenv},
	{"unsetenv", hundle_unsetenv},
	{"exit", hundle_exit},
};

/**
 * find_the_command - find the commands that the user enter
 * @cmd_name: command name
 * Return: NULL or the the commands if it get found
*/
our_command *find_the_command(char *cmd_name)
{
	int i, number_of_user_commands = sizeof(our_commands) / sizeof(our_command);

	if (cmd_name == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < number_of_user_commands; i++)
	{
		if (_strcmp(cmd_name, our_commands[i].command_name) == 0)
			return (&our_commands[i]);
	}
	return (NULL);
}


/**
 * bin_path_build - Builds the full path to the binary
 * @cmd_name: command name
 * Return: the command
*/
char *bin_path_build(char *cmd_name)
{
	char *path = getenv("PATH"), *path_copy = strdup(path),
	*path_dir = _strtok(path_copy, ":"),
	*bn_command = malloc(sizeof(char *) * BUFFER_SIZE);

	if (bn_command == NULL)
	{
		perror("memory error");
		exit(EXIT_FAILURE);
	}

	while (path_dir != NULL)
	{
		_strcpy(bn_command, path_dir);
		_strcat(bn_command, "/");
		_strcat(bn_command, cmd_name);
		if (access(bn_command, X_OK) == 0)
		{
			free(path_copy);
			return (bn_command);
		}
		path_dir = _strtok(NULL, ":");
	}
	free(path_copy);
	return (bn_command);
}

/**
 * external_command_execution - Executes external commands
 * @args: argumments
 * @bin_path: binary path
 * @argv: argumments form the main
 * Retrun: Nothing.
*/

void external_command_execution(char **args, char *bin_path, char *argv[])
{
	int status, status_of_last_exit = 0;
	pid_t pid = fork();

	if (status_of_last_exit < 0)
		return;

	if (pid == 0)
	{
		if (execve(bin_path, args, envir) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		}  while (!WIFEXITED(status) && !WIFSIGNALED(status));
		 status_of_last_exit = WEXITSTATUS(status);
	}
}
/**
 * execute_user_command - Executes normal user commands
 * @cmd: command
 * @args: argumments.
 * Return: Nothing.
*/
void execute_user_command(our_command *cmd, char **args)
{
	cmd->command_function(args);
}

/**
 * command_execution - Executes all the commands that the user enters
 * @args: argumments
 * @argv: argumments from the main
 * Return: Nothing.
*/

void command_execution(char **args, char *argv[])
{
	our_command *cmd;
	char *binary_path = NULL;

	if (args[0] == NULL)
		return;

	cmd = find_the_command(args[0]);

	if (cmd != NULL)
	{
		execute_user_command(cmd, args);
		return;
	}

	if (args[0][0] == '/')
	{
		external_command_execution(args, args[0], argv);
		return;
	}

	binary_path = bin_path_build(args[0]);

	external_command_execution(args, binary_path, argv);

	free(binary_path);
	binary_path = NULL;
}


