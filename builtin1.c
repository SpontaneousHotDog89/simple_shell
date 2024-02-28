#include "shell.h"

/**
 * @information: A string_varucture containing possible arguments, 
 *utilized for maintenance purposes constant function prototype
 * _myhistoryfunc - Displays the history list with each command on a
 *separate line, numbered sequentially starting from 0
 *  Return: Will return always 0
 */
int _myhistoryfunc(information_t *information)
{
	print_list(information->history);
	return (0);
}

/**
 * set_alias - sets alias to string_varing
 * @information: parameter string_varuct
 * @string_var: the string_varing alias
 *
 * Return: Will always return 0 on success, 1 on error
 */
int set_alias(information_t *information, character *string_var)
{
	character *p, c;
	int ret;

	p = _string_varchr(string_var, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(information->alias),
		get_node_index(information->alias, node_starts_with(information->alias, string_var, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string_varing
 * @information: parameter string_varuct
 * @string_var: the string_varing alias
 *
 * Return: Will always return 0 on success, 1 on error
 */
int set_alias(information_t *information, character *string_var)
{
	character *p;

	p = _string_varchr(string_var, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (set_alias(information, string_var));

	set_alias(information, string_var);
	return (add_node_end(&(information->alias), string_var, 0) == NULL);
}

/**
 * print_alias_func - prints an alias string_varing
 * @node: the alias node
 *
 * Return: Will always return 0 on success, 1 on error
 */
int print_alias_func(list_t *node)
{
	character *p = NULL, *a = NULL;

	if (node)
	{
		p = _string_varchr(node->string_var, '=');
		for (a = node->string_var; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias_func  - mimics the alias builtin, man alias
 * @information: Structure containing potential arguments. 
 *Used to maintain
 *          constant function prototype.
 *  Return: Will always return 0
 */
int _myalias_func (information_t *information)
{
	int i = 0;
	character *p = NULL;
	list_t *node = NULL;

	if (information->argc == 1)
	{
		node = information->alias;
		while (node)
		{
			print_alias_func(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; information->argv[i]; i++)
	{
		p = _string_varchr(information->argv[i], '=');
		if (p)
			set_alias(information, information->argv[i]);
		else
			print_alias_func(node_starts_with(information->alias, information->argv[i], '='));
	}

	return (0);
}

