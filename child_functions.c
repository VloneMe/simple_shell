#include "shell.h"

/**
 * execute_child - A execute_child function to create a child process.
 *
 * @command: Tokenized pointer command arguments.
 * @name: Pointer of the name of the shell.
 * @envp: Environmental variables.
 * @loops: number of times for executed loops.
 * Return: Nothing.
 */
void execute_child(char **command, char *name, char **envp, int loops)
{
	int pid, status;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execute_command(command, name, envp, loops);
		exit(0);
	}
	else
	{
		if (waitpid(pid, &status, 0) < 0)
		{
			perror("Error: waitpid failed");
			exit(1);
		}
	}

	free_memory(command);
}


/**
  * dir_changes - This function changes the current working directory.
  *
  * @path: New current working directory.
  * Return: 0 on success, -1 on failure.
  */
int dir_changes(const char *path)
{
	if (path == NULL)
	{
		char *buf = NULL;
		size_t size = 1024;

		path = getcwd(buf, size);
	}

	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}

	return (1);
}
