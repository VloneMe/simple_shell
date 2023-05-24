#include "shell.h"

/**
 * handle_build - handle buitin commands
 * @arv: array of arguments
 *
 * Return: 0 (success)
 */
void(*handle_build(char **arv))(char **arv)
{
	int i, j;
	mybuild T[] = {
		{"exit", handle_exit},
		{"env", print_env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
