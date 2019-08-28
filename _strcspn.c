#include <stdio.h>
#include <stdlib.h>
#include "shell_header.h"

/**
 * _strcspn - count characters until the first
 * occurrence of reject char happens
 *
 * @s: string to be scanned
 * @reject: list of chars to be rejected
 *
 * Return: number of chars counted before the
 * first occurrence of reject
 */
ssize_t _strcspn(const char *s, const char *reject)
{
	unsigned int i = 0;
	unsigned int j = 0;
	ssize_t count = 0;

	while (s[i] != '\0')
	{
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (count);
			j++;
		}
		j = 0;
		count++;
		i++;
	}

	return (count);
}
