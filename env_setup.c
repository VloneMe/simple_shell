#include "shell.h"

/**
 * _setenv - This function sets a new environment variable
 * or modify an existing one.
 *
 * @var_name: pointer environment variable.
 * @value: for the environment variable.
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *var_name, const char *value)
{
	int result = setenv(var_name, value, 1);

	if (var_name == NULL || value == NULL)
	{
		fprintf(stderr, "Error: Variable or value is missing .\n");
		return (-1);
	}
	if (result != 0)
	{
		fprintf(stderr, "Error: Cannot set the environment variable.\n");
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - This function removes an environment variable.
 *
 * @var_name: pointer environment variable to be removed.
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *var_name)
{
	int result = unsetenv(var_name);

	if (var_name == NULL)
	{
		fprintf(stderr, "Error: Variable is missing.\n");
		return (-1);
	}

	if (result != 0)
	{
		fprintf(stderr, "Error: Cannot unset the environment variable.\n");
		return (-1);
	}
	return (0);

}
