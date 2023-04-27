#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <ncurses.h>
#define TOKEN_DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

/*EXTERNAL VAR*/
extern int status_of_last_exit;
extern char **envir;

/*MAIN FUNCTIONS*/
char *_readline(void);
void command_execution(char **args, char *argv[]);
char **parse_line(char *line);
void hundle_env(char **args);

/*EXTERNAL COMMANDS FUNCTIONS*/
void hundle_cd(char **args);
void hundle_setenv(char **args);
void hundle_unsetenv(char **args);
void hundle_echo(char **args);
void hundle_exit(char **args);

/*STRING FUNCTIONS*/
int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void clear_command(char **args);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *str, int c);

/*OWN FUNCTION*/
void *_memcpy(void *dest, const void *src, size_t n);
int _atoi(const char *str);
int _isdigit(int c);

/*ERRORS FUCNTION*/
void hundling_errors(char *command_name);
/**
 * struct our_command - struct that call function based on command
 * @command_name: command name
 * @command_function: function ointer that get called when
 *								the user enter command
*/
typedef struct our_command
{
	char *command_name;
	void (*command_function)(char **args);
} our_command;
#endif

