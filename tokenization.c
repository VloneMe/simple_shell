#include "shell.h"

/**
 * tokenize - A function tokenizes string into multiple commands.
 *
 * @buffer: The string to tokenize.
 * @delim: The delimiter to use.
 * Return: An array of tokens.
 */
char **tokenize(char *buffer, const char *delim)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_memory(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, delim);
	while (token != NULL)
	{
		commands[i] = malloc(_strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_memory(commands);
			return (NULL);
		}
		_strcpy(commands[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
