#include "shell.h"

/**
 * interactive - will return true if shell is interactive mode
 * @information: string_varuct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(information_t *information)
{
	return (isatty(STDIN_FILENO) && information->readfielddes <= 2);
}

/**
 * is_delimiter - checks if character is a delimiter
 * @c: the character to check
 * @delimiter: the delimiter string_varing
 *
 * Return: 1 if true, 0 if false
 */
int is_delimiter(character c, character *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == c)
			return (1);
	return (0);
}

/**
 *_isalphabet - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalphabet(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string_varing to an integer
 *@s: the string_varing to be converted
 *Return: 0 if no numbers in string_varing, converted number otherwise
 */

int _atoi(character *s)
{
	int i, sign_var= 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign_var*= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign_var== -1)
		output = -result;
	else
		output = result;

	return (output);
}
