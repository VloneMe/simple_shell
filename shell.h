#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include "specialFun.h"


/*#### main shell initials ####*/
int main(void);
void handle_signal(int signal);
void _handleEOF(int len, char *buffer);
void _prompt(void);

char **splitstring(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/*#### environment functions ####*/
extern char **environ;
char *_getenv(const char *name);
void print_env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);
void handle_exit(char **arv);

/*#### Chech path functions ####*/ 
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);

/*#### bulder function ####*/
void(*handle_build(char **arv))(char **arv);


/*#### output Functions ####*/
int _putchar(char c);
void _puts(char *str);

/*#### Auxiliarily Functions ####*/
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *name, char *sep, char *value);
int _strToInt(char *str);

/*#### Free memory ####*/
void freearv(char **arv);
void free_list(list_path *head);

#endif
