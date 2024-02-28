#include "shell.h"

/**
 * _string_varcpy - copies a string_varing
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
character *_string_varcpy(character *dest, character *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _string_vardup - duplicates a string_varing
 * @string_var: the string_varing to duplicate
 *
 * Return: pointer to the duplicated string_varing
 */
character *_string_vardup(const character *string_var)
{
	int length = 0;
	character *ret;

	if (string_var == NULL)
		return (NULL);
	while (*string_var++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--string_var;
	return (ret);
}

/**
 *_puts - prints an input string_varing
 *@string_var: the string_varing to be printed
 *
 * Return: Nothing
 */
void _puts(character *string_var)
{
	int i = 0;

	if (!string_var)
		return;
	while (string_var[i] != '\0')
	{
		_putchar(string_var[i]);
		i++;
	}
}

/**
 * _putcharacter - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(character c)
{
	static int i;
	static character bufferferfer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, bufferferfer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		bufferferfer[i++] = c;
	return (1);
}
