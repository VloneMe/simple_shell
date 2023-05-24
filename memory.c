#include "shell.h"

/**
 * free_memory - This function that frees all the memory
 * allocated for commands.
 *
 * @command: Pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_memory(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	for (; command[i] != NULL; i++)
	{
		free(command[i]);
		command[i] = NULL;
	}
	free(command);
}


/**
 * freeMem_and_exit - A function frees all the memory
 * allocated and exit.
 *
 * @command: The pointer to allocated commands memory to free.
 * Return: Nothing.
 */
void freeMem_and_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	for (; command[i] != NULL; i++)
		free(command[i]);

	free(command);
	exit(EXIT_FAILURE);
}
