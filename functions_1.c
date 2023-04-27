#include "shell.h"

/**
* get_line - reads user input
*
* @void: no arguments
*
* Return: command input by user
*/

char *get_line(void)
{
	char *command;
	size_t length;
	ssize_t input;

	command = NULL;
	length = 0;
	input = getline(&command, &length, stdin);

	if (input == -1)
	{
		if (input == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* easier to trace where error occured */
			perror("input error");
			exit(EXIT_FAILURE);
		}
	}

	/* checks if user presses ENTER after input */

	if (command[input - 1] == '\n')
	{
		command[input - 1] = '\0';
	}

	return (command);
}



/**
* my_strcmp - compares two strings
*
* @first_string: pointer to first string
*
* @second_string: pointer to second string
*
* Return: 0 if strings are identical
*
* or difference between the 2 strings
*
*/

int my_strcmp(const char *first_string, const char *second_string)
{
	int index;

	index = 0;

	while (first_string[index] == second_string[index])
	{
		if (first_string[index] == '\0')
		{
			return (0);
		}
		index++;
	}

	return (first_string[index] - second_string[index]);
}

/**
* my_strlen - returns length of a string
*
* @string: string
*
* Return: length of string involved
*/

int my_strlen(char *string)
{
	int length;

	length = 0;

	while (*string != '\0')
	{
		length++;
		string++;
	}

	return (length);
}

/**
* execute_command - execute commands input by user
*
* @command: command string involved
*
* Return: void
*
*/

void execute_command(char *command)
{
	char *arg[COMMAND_LENGTH] = {NULL};
	char error_returned[BUFFER];
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (my_strlen(command) == 0)
	{
		return;
	}

	if (child_pid == -1)
	{
		perror("fork() failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command, arg, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid error");
			exit(EXIT_FAILURE);
		}
		else
		{
			snprintf(error_returned, BUFFER, "%s: command not found\n", command);
			write(STDOUT_FILENO, error_returned, my_strlen(error_returned));
		}
	}
}


/**
* print_prompt - prints $
*
* @void: no arguments
*
* Return: void
*/

void print_prompt(void)
{
	char prompt[] = "$ ";

	if (prompt != NULL)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt));
	}
}

