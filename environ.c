#include "shell.h"

/**
 * _myenv_func - prints the current environment
 * @information: Structure containing potential arguments. Used to
 *maintain constant function prototype
 *
 * Return: Will always return 0
 */
int _myenv_func(information_t *information)
{
	print_list_string_var(information->env);
	return (0);
}

/**
 * _getenv_func - gets the value of an environ variable
 * @information: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
character *_getenv_func(information_t *information, const character *name)
{
	list_t *node = information->env;
	character *p;

	while (node)
	{
		p = starts_with(node->string_var, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @information: Structure containing potential arguments. Used to maintain constant function prototype.
 *  Return: Will always return 0
 */
int _mysetenv(information_t *information)
{
	if (information->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(information, information->argv[1], information->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Will always return 0
 */
int _myunsetenv(information_t *information)
{
	int i;

	if (information->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= information->argc; i++)
		_unsetenv(information, information->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @information: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Will always return 0
 */
int populate_env_list(information_t *information)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	information->env = node;
	return (0);
}
