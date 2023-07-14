#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/* Global variable */
extern char **environ;

/* Macros */
#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "$ "
#define SUCCESS 1
#define FAIL -1
#define NEUTRAL 0

/* Struct */
typedef struct sh_data
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} sh_t;

typedef struct builtin
{
	char *cmd;
	int (*f)(sh_t *data);
} blt_t;

/* Process prototypes */
int read_line(sh_t *data);
int split_line(sh_t *data);
int parse_line(sh_t *data);
int process_cmd(sh_t *data);

/* String prototypes */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_strchr(char *str, char c);
int _strcmp(char *s1, char *s2);

/* More String prototypes */
char *_strcpy(char *dest, char *src);

/* Memory prototypes */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char byt, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int free_data(sh_t *data);

/* Tools prototypes */
void *fill_array(void *ptr, int val, unsigned int size);
void signal_handler(int signo);
char *_getenv(char *path);
void index_cmd(sh_t *data);
void reverse_array(char *arr, int size);

/* More tools prototypes */
char *_itoa(unsigned int num);
int int_len(int num);
int _atoi(char *str);
int print_error(sh_t *data);
int write_history(sh_t *data);
int _isalpha(int c);

/* Builtins */
int abort_prg(sh_t *data);
int change_directory(sh_t *data);
int display_help(sh_t *data);
int handle_builtin(sh_t *data);
int check_builtin(sh_t *data);
#endif /* SIMPLE_SHELL_H */
