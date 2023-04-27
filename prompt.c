#include "shell.h"
/**
 *prompt- displays the shell prompt
 *
 */

void prompt(void)
{
	char *msg = "$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, msg, strlen(msg));
		fflush(stdout);
	}
}
