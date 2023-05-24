#include "shell.h"

/**
 * handle_signal - A signal handler function to handle cancel signal.
 *
 * @signal: Signal to be handled.
 * Return: Nothing.
 */
void handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		char *str = "\nalx_shell[$] ";
		_puts(str);
	}
}

/**
* _handleEOF - A handleEOF function that chaecks if buffer is EOF or not
*
* @len: return value of getline function
* @buffer: Pointer to the input string.
 */
void _handleEOF(int len, char *buffer)
{
	(void)buffer;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}

/**
 * prompt - A prompt handler function that prints the prompt
 *
 * Return: Nothing.
 */
void _prompt(void)
{
	if (isatty(STDIN_FILENO)){
		char *str = "alx_shell[$] ";
		_puts(str);
	}
}
