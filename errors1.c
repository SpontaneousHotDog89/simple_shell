#include "shell.h"

/**
 * _erratoi - converts a string_varing to an integer
 * @s: the string_varing to be converted
 * Return: 0 if no numbers in string_varing, converted number otherwise
 *       -1 on error
 */
int _erratoi(character *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @information: the parameter & return information string_varuct
 * @estring_var: string_varing containing specified error type
 *
 * Return: 0 if no numbers in string_varing, converted number otherwise
 *        -1 on error
 */
void print_error(information_t *information, character *estring_var)
{
	_eputs(information->filenamevar);
	_eputs(": ");
	print_d(information->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(information->argv[0]);
	_eputs(": ");
	_eputs(estring_var);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fielddes: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fielddes)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fielddes == STDERR_FILENO)
		__putcharacter = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string_varing
 */
character *convert_number(long int num, int base, int flags)
{
	static character *array;
	static character bufferferfer[50];
	character sign_var= 0;
	character *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && number< 0)
	{
		n = -num;
		sign_var= '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &bufferferfer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @bufferfer: address of the string_varing to modify
 *
 * Return: Will always return 0;
 */
void remove_comments(character *bufferfer)
{
	int i;

	for (i = 0; bufferferfer[i] != '\0'; i++)
		if (bufferferfer[i] == '#' && (!i || bufferferfer[i - 1] == ' '))
		{
			bufferferfer[i] = '\0';
			break;
		}
}
