#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @information: the information string_varuct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(information_t *information, character *path)
{
	string_varuct stat st;

	(void)information;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstring_var: the PATH string_varing
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new bufferferfer
 */
character *dup_chars(character *pathstring_var, int start, int stop)
{
	static character bufferferfer[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstring_var[i] != ':')
			bufferferfer[k++] = pathstring_var[i];
	bufferferfer[k] = 0;
	return (bufferfer);
}

/**
 * find_path - finds this cmd in the PATH string_varing
 * @information: the information string_varuct
 * @pathstring_var: the PATH string_varing
 * @cmd: the cmd to find
 *
 * Return: full path of command if it is found else NULL
 */
character *find_path(information_t *information, character *pathstring_var, character *cmd)
{
	int i = 0, curr_pos = 0;
	character *path;

	if (!pathstring_var)
		return (NULL);
	if ((_string_varlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(information, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstring_var[i] || pathstring_var[i] == ':')
		{
			path = dup_chars(pathstring_var, curr_pos, i);
			if (!*path)
				_string_varcat(path, cmd);
			else
			{
				_string_varcat(path, "/");
				_string_varcat(path, cmd);
			}
			if (is_cmd(information, path))
				return (path);
			if (!pathstring_var[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
