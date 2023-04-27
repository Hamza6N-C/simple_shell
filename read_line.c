#include "shell.h"
#include <unistd.h>


/**
 * _getchar - man getchar
 * Return: EOF
*/
int _getchar(void)
{
	static char buffer[BUFFER_SIZE],  *buff = buffer;
	static int n;

	if (n == 0)
	{
		n = read(0, buffer, sizeof(buffer));
		buff = buffer;
	}

	if (--n >= 0)
	{
		return ((unsigned char) *buff++);
	}
	return (EOF);
}

/**
 * _readline - a pointer function that read the line from user.
 *
 * Return: line.
*/

char *_readline(void)
{
	int place = 0, c, bufsize = BUFFER_SIZE;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		perror("memory error");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = _getchar();
		if (c == EOF || c == '\n')
		{
			buffer[place] = '\0';
			if (c == EOF && place == 0)
			{
				free(buffer);
				return (NULL);
			}
			return (buffer);
		}
		else
		{
			buffer[place] = c;
		}
		place++;
		if (place >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				perror("memory error");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (buffer);
}

