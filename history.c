#include "shell.h"

/**
 * get_history_file - gets the history file
 * @information: parameter string_varuct
 *
 * Return: allocated string_varing containg history file
 */

character *get_history_file(information_t *information)
{
	character *bufferferfer, *dir;

	dir = _getenv_func(information, "HOME=");
	if (!dir)
		return (NULL);
	bufferferfer= malloc(sizeof(char) * (_string_varlen(dir) + _string_varlen(HIST_FILE) + 2));
	if (!bufferfer)
		return (NULL);
	bufferferfer[0] = 0;
	_string_varcpy(bufferferfer, dir);
	_string_varcat(bufferferfer, "/");
	_string_varcat(bufferferfer, HIST_FILE);
	return (bufferfer);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @information: the parameter string_varuct
 *
 * Return: 1 on success, else -1
 */
int write_history(information_t *information)
{
	ssize_t fielddes;
	character *filename = get_history_file(information);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fielddes = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fielddes == -1)
		return (-1);
	for (node = information->history; node; node = node->next)
	{
		_putsfielddes(node->string_var, fielddes);
		_putfielddes('\n', fielddes);
	}
	_putfielddes(BUF_FLUSH, fielddes);
	close(fielddes);
	return (1);
}

/**
 * read_history - reads history from file
 * @information: the parameter string_varuct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(information_t *information)
{
	int i, last = 0, linecount = 0;
	ssize_t fielddes, rdlen, fsize = 0;
	string_varuct stat st;
	character *bufferferfer= NULL, *filename = get_history_file(information);

	if (!filename)
		return (0);

	fielddes = open(filename, O_RDONLY);
	free(filename);
	if (fielddes == -1)
		return (0);
	if (!fstat(fielddes, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	bufferferfer= malloc(sizeof(char) * (fsize + 1));
	if (!bufferfer)
		return (0);
	rdlen = read(fielddes, bufferferfer, fsize);
	bufferferfer[fsize] = 0;
	if (rdlen <= 0)
		return (free(bufferfer), 0);
	close(fielddes);
	for (i = 0; i < fsize; i++)
		if (bufferferfer[i] == '\n')
		{
			bufferferfer[i] = 0;
			build_history_list(information, bufferferfer+ last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(information, bufferferfer+ last, linecount++);
	free(bufferfer);
	information->histcount = linecount;
	while (information->histcount-- >= HIST_MAX)
		delete_node_at_index(&(information->history), 0);
	renumber_history(information);
	return (information->histcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @information: Structure containing potential arguments. Used to maintain
 * @bufferfer: bufferferfer
 * @linecount: the history linecount, histcount
 *
 * Return: Will always return 0
 */
int build_history_list(information_t *information, character *bufferferfer, int linecount)
{
	list_t *node = NULL;

	if (information->history)
		node = information->history;
	add_node_end(&node, bufferferfer, linecount);

	if (!information->history)
		information->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @information: Structure containing potential arguments
 *
 * Return: the new histcount
 */
int renumber_history(information_t *information)
{
	list_t *node = information->history;
	int i = 0;

	while (node)
	{
		node->number= i++;
		node = node->next;
	}
	return (information->histcount = i);
}
