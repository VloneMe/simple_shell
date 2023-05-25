#include "shell.h"

Alias *aliases = NULL;

/**
 * handle_alias - Handles the alias command.
 * @command: The tokenized command.
 */
void handle_alias(char **command)
{
	if (command[1] == NULL)
		print_aliases();
	else
	{
		int i = 1;

		while (command[i] != NULL)
		{
			char *equal_sign = strchr(command[i], '=');

			if (equal_sign != NULL)
				define_alias(command[i]);
			else
				print_alias_value(command[i]);
			i++;
		}
	}
}

/**
 * print_aliases - Prints all aliases.
 */
void print_aliases(void)
{
	Alias *current = aliases;

	while (current != NULL)
	{
		printf("%s='%s'\n", current->name, current->value);
		current = current->next;
	}
}

/**
 * print_alias_value - Prints the value of an alias.
 * @name: The name of the alias.
 */
void print_alias_value(char *name)
{
	Alias *alias = find_alias(name);

	if (alias != NULL)
		printf("%s='%s'\n", alias->name, alias->value);
	else
		printf("Alias '%s' not found\n", name);
}

/**
 * define_alias - Defines an alias.
 * @alias: The alias string.
 */
void define_alias(char *alias)
{
	char *name = strtok((char *)alias, "=");
	char *value = strtok(NULL, "=");

	Alias *existing_alias = find_alias(name);

	if (existing_alias != NULL)
	{
		free(existing_alias->value);
		existing_alias->value = _strdup(value);
	}
	else
	{
		Alias *new_alias = create_alias(name, value);

		add_alias(new_alias);
	}
}

/**
 * find_alias - Finds an alias by name.
 * @name: The name of the alias.
 * Return: The found alias, or NULL if not found.
 */
Alias *find_alias(char *name)
{
	Alias *current = aliases;

	while (current != NULL)
	{
		if (_strcmp(name, current->name) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

/**
 * create_alias - Creates a new alias.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * Return: The created alias.
 */
Alias *create_alias(char *name, char *value)
{
	Alias *new_alias = malloc(sizeof(Alias));

	new_alias->name = _strdup(name);
	new_alias->value = _strdup(value);
	new_alias->next = NULL;
	return (new_alias);
}

/**
 * add_alias - Adds an alias to the list.
 * @alias: The alias to add.
 */
void add_alias(Alias *alias)
{
	if (aliases == NULL)
		aliases = alias;
	else
	{
		Alias *current = aliases;

		while (current->next != NULL)
			current = current->next;
		current->next = alias;
	}
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string,
 *         or NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	size_t len, i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';

	return (dup);
}


/**
 * _intStr - Converts an integer to a string.
 *
 * @num: The integer to convert.
 * @str: The buffer to store the resulting string.
 * Return: A pointer to the resulting string.
 */
char *_intStr(int num, char *str)
{
	int i = 0;
	int is_negative = 0;
	int start = 0;
	int end = i - 1;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
		str[i++] = '-';

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	str[i] = '\0';
	return (str);
}

