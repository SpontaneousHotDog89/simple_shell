#include "shell.h"

/**
 * clear_information - initializes information_t string_varuct
 * @information: string_varuct address
 */
void clear_information(information_t *information)
{
	information->arg = NULL;
	information->argv = NULL;
	information->path = NULL;
	information->argc = 0;
}

/**
 * set_information - initializes information_t string_varuct
 * @information: string_varuct address
 * @av: argument vector
 */
void set_information(information_t *information, character **av)
{
	int i = 0;

	information->filenamevar = av[0];
	if (information->arg)
	{
		information->argv = string_vartow(information->arg, " \t");
		if (!information->argv)
		{

			information->argv = malloc(sizeof(character *) * 2);
			if (information->argv)
			{
				information->argv[0] = _string_vardup(information->arg);
				information->argv[1] = NULL;
			}
		}
		for (i = 0; information->argv && information->argv[i]; i++)
			;
		information->argc = i;

		replace_alias(information);
		replace_vars(information);
	}
}

/**
 * free_information - frees information_t string_varuct fields
 * @information: string_varuct address
 * @all: true if freeing all fields
 */
void free_information(information_t *information, int all)
{
	freestring(information->argv);
	information->argv = NULL;
	information->path = NULL;
	if (all)
	{
		if (!information->cmd_bufferfer)
			free(information->arg);
		if (information->env)
			free_list(&(information->env));
		if (information->history)
			free_list(&(information->history));
		if (information->alias)
			free_list(&(information->alias));
		freestring(information->environ);
			information->environ = NULL;
		bfree((void **)information->cmd_bufferfer);
		if (information->readfielddes > 2)
			close(information->readfielddes);
		_putchar(BUF_FLUSH);
	}
}
