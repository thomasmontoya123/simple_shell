#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * _getenv - get the environment variable from the $path
 * 
 * @name: the name of the variable (e.g. "PATH")
 * 
 * Return: The full variable, otherwise NULL
 */ 
char *_getenv(const char *name)
{
	extern char **environ;
    int namelen = strlen(name);
	char **ptr;
	char *out;

	ptr = environ;

	while (*ptr != NULL)
	{
		if (strncmp(*ptr, name, namelen) == 0)
		{
			out = *ptr + namelen;
			return (out);
		}
		ptr++;
	}

	return (NULL);
}