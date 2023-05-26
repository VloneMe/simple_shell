#include "shell.h"

/**
  * dir_changes - This function changes the current working directory.
  *
  * @directory: New current working directory.
  * Return: 0 on success, -1 on failure.
  */
int dir_changes(char *directory)
{
	char *current_dir = NULL;
	char *home_dir = getenv("HOME");

	if (directory == NULL || *directory == '\0')
	{
		directory = home_dir;
		if (directory == NULL)
		{
			fprintf(stderr, "cd: %s: No $HOME variable set\n", directory);
			return (-1);
		}
	}
	if (strcmp(directory, "-") == 0)
	{
		directory = getenv("OLDPWD");
		if (directory == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (-1);
		}
		printf("%s\n", directory);
	}
	current_dir = getenv("PWD");
	if (current_dir == NULL)
	{
		fprintf(stderr, "cd: PWD not set\n");
		return (-1);
	}
	if (chdir(directory) != 0)
	{
		perror("cd");
		return (-1);
	}
	if (setenv("PWD", getcwd(NULL, 0), 1) != 0)
	{
		perror("cd");
		return (-1);
	}
	if (setenv("OLDPWD", current_dir, 1) != 0)
	{
		perror("cd");
		return (-1);
	}
	return (0);
}
