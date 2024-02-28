#include "shell.h"

/**
 * _string_varlen - returns the length of a string_varing
 * @s: the string_varing whose length to check
 *
 * Return: integer length of string_varing
 */
int _string_varlen(character *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _string_varcmp - compares two strings using lexicographic comparison
 * @s1: the first string_varang
 * @s2: the second string_varang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _string_varcmp(character *s1, character *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string_varing to search
 * @needle: the substring_varing to find
 *
 * Return: address of next character of haystack or NULL
 */
character *starts_with(const character *haystack, const character *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((character *)haystack);
}

/**
 * _string_varcat - concatenates two string_varings
 * @dest: the destination bufferferfer
 * @src: the source bufferferfer
 *
 * Return: pointer to destination bufferferfer
 */
character *_string_varcat(character *dest, character *src)
{
	character *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
