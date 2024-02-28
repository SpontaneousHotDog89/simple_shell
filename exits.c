#include "shell.h"

/**
 **_string_varncpy - copies a string_varing
 *@dest: the destination string_varing to be copied to
 *@src: the source string_varing
 *@n: the amount of characters to be copied
 *Return: the concatenated string_varing
 */
character *_string_varncpy(character *dest, character *src, int n)
{
	int i, j;
	character *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_string_varncat - concatenates two string_varings
 *@dest: the first string_varing
 *@src: the second string_varing
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string_varing
 */
character *_string_varncat(character *dest, character *src, int n)
{
	int i, j;
	character *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_string_varchr - locates a character in a string_varing
 *@s: the string_varing to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
character *_string_varchr(character *s, character c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);

}
