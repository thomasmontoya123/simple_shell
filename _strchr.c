#include <stdio.h>
#include <stdlib.h>

/**
 * _strchr - finds the pointer to the first
 * occurrence of a character
 *
 * @s: string to scan
 * @c: the char to find
 *
 * Return: pointer to the first match -> success
 * NULL -> failure
 */
char *_strchr(const char *s, int c)
{
	const char *ptr;

	if (s == NULL)
		return (NULL);

	ptr = s;

	while (*ptr != '\0')
	{
		if (*ptr == c)
			return ((char *)ptr);
		ptr++;
	}

	return (NULL);
}

