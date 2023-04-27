#include "shell.h"
/**
 *handle_error - prints error msg & exits prgm with failure status
 *@message: error message to be printed
 *
 */

void handle_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
