#include "shell.h"
/**
 *commad_execute - Function that executes a command.
 *@args: Array of arguments.
 *Return: 1 if successful, 0 otherwise.
 */
int commad_execute(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}
		if (_strcmp(args[0], "cd") == 0)
	{
		return (cd_command(args));
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		return (echo_command(args));
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		return (exit_command(args));
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		return (setenv_command(args));
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		return (unsetenv_command(args));
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
		return (hundle_alias(args));
	}
	else if (_strcmp(args[0], "run_script") == 0)
	{
		return (run_script(args[1]));
	}
	else
	{
		return (launch(args));
	}
}
