#include <stdlib.h>

/**
 * _memset - fills memory with a constant byte.
 * @s: Array of chars
 * @b: char to fill
 * @n: number of instances
 * Return: Pointer to array filled with n ocurrences of b
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: number of spaces
 * @size: size of
 * Return: NULL if fails to allocate, buf if success
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *buf;
	int dim = nmemb * size;

	if (nmemb <= 0 || size <= 0)
		return (NULL);

	buf = malloc(dim);

	if (buf == NULL)
		return (NULL);

	_memset(buf, '\0', dim);

	return (buf);
}

