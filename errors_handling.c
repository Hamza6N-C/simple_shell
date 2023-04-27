#include "shell.h"
/**
 * hundling_errors - print error message and return
 * @command_name: name of the command that caused the error
 * Return: Nothing
*/
void hundling_errors(char *command_name)
{
	perror(command_name);
}

