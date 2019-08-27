#include <errno.h>
#include "shell_header.h"

/**
 * _getenv - get the environment variable from the $path
 *
 * @name: the name of the variable (e.g. "PATH")
 *
 * Return: The full variable, otherwise NULL
 */
char *_getenv(const char *name)
{
	int namelen = strlen(name);
	char **ptr;
	char *out;

	ptr = environ;

	while (*ptr != NULL)
	{
		if (strncmp(*ptr, name, namelen) == 0)
		{
			out = *ptr + namelen + 1;
			return (out);
		}
		ptr++;
	}

	return (NULL);
}

