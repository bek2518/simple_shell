#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <string.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


/**
 * struct data - structure that conatains data
 * @argv: argument vector
 * @input: commandline written by user
 * @args: token of the commandline
 * @status: last status of shell
 * @counter: line counter
 * @_environ: environment
 * @pid: process ID of the shell
 */

typedef struct data
{
	char **argv;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct builtin_s - builtin structure
 * @name: name of the command builtin
 * @f: datat type pointer function
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
}builtin_t;


/**
 * environ: pounts to an array of pointers to strings
 */

extern char **environ;
/**
 * aux_str.c
 */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/**
 * aux_mem
 */

void _memcpy(void *newptr,const  void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * aux_str2.c
 */

char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);

/**
 * get_line.c
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **linepre, size_t *n, FILE *stram);

/**
 * get_builtin.c
 */
int (*get_builtin(char *cmd))(data_shell *datash);


/**
 * env1.c
 */
char *_getenv(const char *name, char **environ);
int _env(data_shell *datash);


/**
 * exec_line.c
 */
int exec_line(data_shell *datash);

/**
 * cmd_exec.c
 */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

#endif
