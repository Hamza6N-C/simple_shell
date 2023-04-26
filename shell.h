#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

int handle_the_exit(char **args);
char *get_line(void);
char *get_path_of_command(char *command);
char *parse_command(char *input);
char **parse_arguments(char *line);
void free_arguments(char **args);
void cd_command(char *path);
void env_command(char **envp);
void command_execute(char *command, char **args, char **envp);

#endif
