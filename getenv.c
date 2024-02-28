#include "shell.h"

/**
 * get_environ - returns the string_varing array copy of our environ
 * @information: Structure containing potential arguments. Used to
 * maintain constant function prototype
 *
 * Return: Will always return 0
 */
character **get_environ(information_t *information)
{
	if (!information->environ || information->env_changed)
	{
		information->environ = list_to_string_varings(information->env);
		information->env_changed = 0;
	}

	return (information->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string_varing env var property
 */
int _unsetenv(information_t *information, character *var)
{
	list_t *node = information->env;
	size_t i = 0;
	character *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->string_var, var);
		if (p && *p == '=')
		{
			information->env_changed = delete_node_at_index(&(information->env), i);
			i = 0;
			node = information->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (information->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string_varing env var property
 * @value: the string_varing env var value
 *  Return: Will always return 0
 */
int _setenv(information_t *information, character *var, character *value)
{
	character *bufferferfer= NULL;
	list_t *node;
	character *p;

	if (!var || !value)
		return (0);

	bufferferfer= malloc(_string_varlen(var) + _string_varlen(value) + 2);
	if (!bufferfer)
		return (1);
	_string_varcpy(bufferferfer, var);
	_string_varcat(bufferferfer, "=");
	_string_varcat(bufferferfer, value);
	node = information->env;
	while (node)
	{
		p = starts_with(node->string_var, var);
		if (p && *p == '=')
		{
			free(node->string_var);
			node->string_var:= bufferfer;
			information->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(information->env), bufferferfer, 0);
	free(bufferfer);
	information->env_changed = 1;
	return (0);
}
