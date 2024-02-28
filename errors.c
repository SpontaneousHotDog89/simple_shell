#include "shell.h"

/**
 *_eputs - prints an input string_varing
 * @string_var: the string_varing to be printed
 *
 * Return: Nothing
 */
void _eputs(character *string_var)
{
	int i = 0;

	if (!string_var)
		return;
	while (string_var[i] != '\0')
	{
		_eputchar(string_var[i]);
		i++;
	}
}

/**
 * _eputcharacter - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(character c)
{
	static int i;
	static character bufferferfer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, bufferferfer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		bufferferfer[i++] = c;
	return (1);
}

/**
 * _putfielddes - writes the character c to given fielddes
 * @c: The character to print
 * @fielddes: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfielddes(character c, int fielddes)
{
	static int i;
	static character bufferferfer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fielddes, bufferferfer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		bufferferfer[i++] = c;
	return (1);
}

/**
 *_putsfielddes - prints an input string_varing
 * @string_var: the string_varing to be printed
 * @fielddes: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfielddes(character *string_var, int fielddes)
{
	int i = 0;

	if (!string_var)
		return (0);
	while (*string_var)
	{
		i += _putfielddes(*string_var++, fielddes);
	}
	return (i);
}
