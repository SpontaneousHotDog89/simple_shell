#include "shell.h"

/**
 * **string_vartow - splits a string_varing into words. Repeat delimiteriters are ignored
 * @string_var: the input string_varing
 * @d: the delimiter string_varing
 *
 * Return: a pointer to an array of string_varings, or NULL on failure
 */

character **string_vartow(character *string_var, character *d)
{
	int i, j, k, m, numwords = 0;
	character **s;

	if (string_var == NULL || string_var[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; string_var[i] != '\0'; i++)
		if (!is_delimiter(string_var[i], d) && (is_delimiter(string_var[i + 1], d) || !string_var[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(character *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delimiter(string_var[i], d))
			i++;
		k = 0;
		while (!is_delimiter(string_var[i + k], d) && string_var[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = string_var[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **string_vartow2 - splits a string_varing into words
 * @string_var: the input string_varing
 * @d: the delimiter
 * Return: a pointer to an array of string_varings, or NULL on failure
 */
character **string_vartow2(character *string_var, character d)
{
	int i, j, k, m, numwords = 0;
	character **s;

	if (string_var== NULL || string_var[0] == 0)
		return (NULL);
	for (i = 0; string_var[i] != '\0'; i++)
		if ((string_var[i] != d && string_var[i + 1] == d) ||
		    (string_var[i] != d && !string_var[i + 1]) || string_var[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(character *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (string_var[i] == d && string_var[i] != d)
			i++;
		k = 0;
		while (string_var[i + k] != d && string_var[i + k] && string_var[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = string_var[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
