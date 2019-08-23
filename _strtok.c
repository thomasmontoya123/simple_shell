#include <stdio.h>
#include <string.h>
#include "shell_header.h"

/**
 * _strtok_mod - String to token with save pointer
 * @str: String to evaluate
 * @delim: Array of delimitators
 * @save_ptr: Pointer who saves the next word
 * Return: A token
 */
char *_strtok_mod(char *str, const char *delim, char **save_ptr)
{
	char *end;

	if (str == NULL)
		str = *save_ptr;
	if (*str == '\0')
	{
		*save_ptr = str;
		return (NULL);
	}

	/* Moves the pointer to the span */
	str += _strspn(str, delim);

	if (*str == '\0')
	{
		*save_ptr = str;
		return (NULL);
	}

	end = str + strcspn(str, delim);

	if (*end == '\0')
	{
		*save_ptr = end;
		return (str);
	}

	*end = '\0';
	*save_ptr = end + 1;
	return (str);
}

/**
 * _strtok - String to token
 * @str: String to evaluate
 * @delimiters: Array of delimitators
 * Return: A token
 */
char *_strtok(char *str, const char *delimiters)
{
	static char *oldstr;

	return (_strtok_mod(str, delimiters, &oldstr));
}

