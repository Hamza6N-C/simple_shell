#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#define PATH_SIZE 4096
/**
 * hundle_cd - implement cd command
 * @args: arguments
 * Return: Nothing
*/
void hundle_cd(char **args)
{
	char *dir, the_old_pwd[PATH_SIZE], *current_directory;

	if (args[1] == NULL)
		dir = getenv("HOME");
	else if (_strcmp(args[1], "-") == 0)
		dir = getenv("OLDPWD");
	else
		dir = args[1];

	if (dir == NULL)
	{
		hundling_errors("cd");
		return;
	}

	if (getcwd(the_old_pwd, PATH_SIZE) == NULL)
	{
		hundling_errors("cd");
		return;
	}

	if (chdir(dir) == -1)
	{
		hundling_errors("cd");
		return;
	}
	current_directory = getcwd(NULL, 0);
	if (current_directory == NULL)
	{
		hundling_errors("cd");
		return;
	}
	if (setenv("PWD", current_directory, 1) == -1)
	{
		hundling_errors("cd");
		return;
	}
}

/**
 * hundle_exit - implement exit command
 * @args: arguments
 * Return: Nothing.
*/

void hundle_exit(char **args)
{
	int status, i, is_digit, string_length, huge_number;
	unsigned int ustatus;

	if (args[1] != NULL)
	{
		ustatus = _atoi(args[1]);
		is_digit = 1;
		string_length = 0;
		huge_number = ustatus > (unsigned int)INT_MAX;

		for (i = 0; args[1][i] != '\0'; i++)
		{
			if (!_isdigit(args[1][i]))
			{
				is_digit = 0;
				break;
			}
			string_length++;
		}
		if (!is_digit || string_length > 10 || huge_number)
		{
			perror("exit");
			exit(2);
		}
		status = (int)ustatus;
		exit(status);
	}
	else
	{
		exit(0);
	}
}

/**
 * hundle_env - implement env command
 * @args: arguments
 * Return: Nothing.
*/

void hundle_env(char **args)
{
	char **envptr = envir;

	if (args == NULL)
		return;

	while (*envptr != NULL)
	{
		write(STDOUT_FILENO, *envptr, _strlen(*envptr));
		write(STDOUT_FILENO, "\n", 1);
		envptr++;
	}

}
/**
 * hundle_setenv - implement setenv command
 * @args: arguments.
 * Return: Nothing
*/

void hundle_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		perror("setenv");
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return;
	}

}

/**
 * hundle_unsetenv - implement unsetenv command
 * @args: arguments
 * Return: Nothing
*/

void hundle_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		perror("unsetenv");
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return;
	}

}

