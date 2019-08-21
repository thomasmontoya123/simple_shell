#include "shell_header.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: original pointer
 * @old_size: size of ptr
 * @new_size: new size
 *
 * Return: pointer to the new block of memory
 *
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr;
	unsigned int i;
	unsigned int size;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		newptr = malloc(new_size * sizeof(char));
		if (newptr == NULL)
			return (NULL);
		return (newptr);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	newptr = malloc(new_size * sizeof(char));

	if (old_size > new_size)
		size = new_size;
	else
	{
		size = old_size;
	}

	for (i = 0; i < size; i++)
	{
		newptr[i] = *((char *)ptr + i);
	}
	free(ptr);
	return (newptr);
}

