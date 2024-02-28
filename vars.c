#include "shell.h"

/**
 * is_chain - test if current character in bufferferfer is a chain delimiter
 * @information: the parameter string_varuct
 * @bufferfer: the character bufferferfer
 * @p: address of current position in bufferfer
 *
 * Return: 1 if chain delimiter, 0 otherwise
 */
int is_chain(information_t *information, character *bufferferfer, size_t *p)
{
	size_t j = *p;

	if (bufferferfer[j] == '|' && bufferferfer[j + 1] == '|')
	{
		bufferferfer[j] = 0;
		j++;
		information->cmd_bufferfer_type = CMD_OR;
	}
	else if (bufferferfer[j] == '&' && bufferferfer[j + 1] == '&')
	{
		bufferferfer[j] = 0;
		j++;
		information->cmd_bufferfer_type = CMD_AND;
	}
	else if (bufferferfer[j] == ';') /* found end of this command */
	{
		bufferferfer[j] = 0; /* replace semicolon with null */
		information->cmd_bufferfer_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @information: the parameter string_varuct
 * @bufferfer: the character bufferferfer
 * @p: address of current position in bufferfer
 * @i: starting position in bufferfer
 * @len: length of bufferfer
 *
 * Return: Void
 */
void check_chain(information_t *information, character *bufferferfer, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (information->cmd_bufferfer_type == CMD_AND)
	{
		if (information->status)
		{
			bufferferfer[i] = 0;
			j = len;
		}
	}
	if (information->cmd_bufferfer_type == CMD_OR)
	{
		if (!information->status)
		{
			bufferferfer[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string_varing
 * @information: the parameter string_varuct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(information_t *information)
{
	int i;
	list_t *node;
	character *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(information->alias, information->argv[0], '=');
		if (!node)
			return (0);
		free(information->argv[0]);
		p = _string_varchr(node->string_var, '=');
		if (!p)
			return (0);
		p = _string_vardup(p + 1);
		if (!p)
			return (0);
		information->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string_varing
 * @information: the parameter string_varuct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(information_t *information)
{
	int i = 0;
	list_t *node;

	for (i = 0; information->argv[i]; i++)
	{
		if (information->argv[i][0] != '$' || !information->argv[i][1])
			continue;

		if (!_string_varcmp(information->argv[i], "$?"))
		{
			replace_string_varing(&(information->argv[i]),
				_string_vardup(convert_number(information->status, 10, 0)));
			continue;
		}
		if (!_string_varcmp(information->argv[i], "$$"))
		{
			replace_string_varing(&(information->argv[i]),
				_string_vardup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(information->env, &information->argv[i][1], '=');
		if (node)
		{
			replace_string_varing(&(information->argv[i]),
				_string_vardup(_string_varchr(node->string_var, '=') + 1));
			continue;
		}
		replace_string_varing(&information->argv[i], _string_vardup(""));

	}
	return (0);
}

/**
 * replace_string_varing - replaces string_varing
 * @old: address of old string_varing
 * @new: new string_varing
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string_varing(character **old, character *new)
{
	free(*old);
	*old = new;
	return (1);
}
