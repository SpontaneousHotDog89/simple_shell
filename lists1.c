#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_string_varings - returns an array of string_varings of the list->string_var
 * @head: pointer to first node
 *
 * Return: array of string_varings
 */
character **list_to_string_varings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	character **string_vars;
	character *string_var;

	if (!head || !i)
		return (NULL);
	string_vars = malloc(sizeof(character *) * (i + 1));
	if (!string_vars)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		string_var = malloc(_string_varlen(node->string_var) + 1);
		if (!string_var)
		{
			for (j = 0; j < i; j++)
				free(string_vars[j]);
			free(string_vars);
			return (NULL);
		}

		string_var = _string_varcpy(string_var, node->string_var);
		string_vars[i] = string_var;
	}
	string_vars[i] = NULL;
	return (string_vars);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->string_var ? h->string_var : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string_varing starts with prefix
 * @node: pointer to list head
 * @prefix: string_varing to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, character *prefix, character c)
{
	character *p = NULL;

	while (node)
	{
		p = starts_with(node->string_var, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
