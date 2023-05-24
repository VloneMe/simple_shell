#include "shell.h"

/**
 * handle_exit - exits the shell
 * @arv: array of words of the entered line
 */
void handle_exit(char **arv)
{
	int i, n;

	if (arv[1])
	{
		n = _strToInt(arv[1]);
		if (n <= -1)
			n = 2;
		freearv(arv);
		exit(n);
	}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
	exit(0);
}

/**
 * _strToInt - convert string into an integer
 * @str: pointer to string
 *
 * Return: converted string
 */
int _strToInt(char *str)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
	{
		if (str[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (str[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * print_env - This prints the current environment variables
 * @arv: array of arguments
 */
void print_env(char **arv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}

}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @arv: array of entered words
 */
void _setenv(char **arv)
{
	int i, j, k;

	if (!arv[1] || !arv[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = _strcat(arv[1], "=", arv[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * _unsetenv - Remove an environment variable
 * @arv: array of entered words
 */
void _unsetenv(char **arv)
{
	int i, j;

	if (!arv[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
