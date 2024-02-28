#include "shell.h"

/**
 * freeaddress - will free a pointer
 * @ptr: address of the pointer that is to be freed
 *
 * Return: Will return 1 if ptr is freed, else 0.
 */
int freeaddress(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
