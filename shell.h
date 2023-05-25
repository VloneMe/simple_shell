#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*### Main program Shell file ###*/
int main(int argc, char **argv, char **envp);

/*### Shell environment control ###*/
int _setenv(const char *var_name, const char *value);
int _unsetenv(const char *var_name);

/*### functions to Initialize shell ###*/
void prompt_handler(void);
void handle_signal(int signals);
void handle_eof(char *buffer);
void handle_exit(char **input_command);


/*### functions to child process Creation ###*/
void execute_child(char **command, char *shell_name, char **envp, int loops);
int dir_changes(char *directory);


/*### functions to execute command ###*/
void execute_command(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **_dirsPATH(char **env);
void command_error(char *name, int loops, char **command);


/*### functions to tokenize input ###*/
char **tokenize(char *buffer, const char *delim);


/*### functions to free memory ###*/
void free_memory(char **command);
void freeMem_and_exit(char **command);


/*### Auxiliary functions ###*/
int _strcmp(char *str1, char *str2);
unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strint(char *s);
char *_strcat(char *dest, char *src);


/**
 * struct Alias - Structure for storing an alias.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: Pointer to the next alias.
 */
typedef struct Alias
{
	char *name;
	char *value;
	struct Alias *next;
} Alias;

/*### Alias handler functions ###*/
void handle_alias(char **command);
void print_aliases(void);
void print_alias_value(char *name);
void define_alias(char *alias);
Alias *find_alias(char *name);
Alias *create_alias(char *name, char *value);
void add_alias(Alias *alias);
char *_strdup(char *str);
char *_intStr(int num, char *str);


#endif /*### _SHELL_H_ ###*/

