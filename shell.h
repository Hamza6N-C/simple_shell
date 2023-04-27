#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

/* Constants */
#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"
#define ARG_MAX 4096
#define AND 1
#define OR 2


/* Function prototypes */
void prompt(void);
char *read_line(void);
char **parse_line(char *line);
int commad_execute(char **args);
void handle_error(char *message);
int cd_command(char **args);
int echo_command(char **args);
int exit_command(char **args);
int setenv_command(char **args);
int unsetenv_command(char **args);
int hundle_alias(char **args);
int run_script(char *filename);
int launch(char **args);
int file_input(char *filename);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *getpid_string(void);
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);



#endif
