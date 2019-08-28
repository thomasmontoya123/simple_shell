#include "shell_header.h"
#include "pathmgmt.h"

/**
* buildenv_key_val - Builds key value
* @name: Name 
* @vale: Value for the variable.
* 
* return: string key value
*/

char *buildenv_key_val(const char *name, const char *value)
{
	char *keyval;

	int namelen = strlen(name);
	int valen = strlen(value);

	keyval = calloc(namelen + valen + 2, sizeof(char));
	if (keyval == NULL)
		return (NULL);

	strcat(keyval, name);
	strcat(keyval, "=");
	strcat(keyval, value);
	strcat(keyval, "\0");

	return (keyval);
}

/**
* environlen - enrionment len.
* 
* return: len
*/

unsigned int environlen(void)
{
	extern char **environ;
	char **ptr;
	unsigned int count = 0;

	ptr = environ;

	while (*ptr != NULL)
	{
		count++;
		ptr++;
	}

	return (count);
}

/**
* _setenv - Function to handle the setenv.
* @name: Name of the variable to be set.
* @vale: Value for the variable.
* @overwrite: flag
*
* return: -1 if it fails
*/

int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char **newenviron = NULL;
	char *match, *str_to_add;
	int i, ptrlen;

	int envlen = environlen();

	if (name == NULL || value == NULL)
		return (-1);

	str_to_add = buildenv_key_val(name, value); //TODO: FREE

	match = _getenv(name);
	if (match == NULL)
	{
		newenviron = calloc(envlen + 2, sizeof(char *));
		for (i = 0; i < envlen; i++)
		{
			ptrlen = strlen(environ[i]);
			newenviron[i] = calloc(ptrlen, sizeof(char));
			strcpy(newenviron[i], environ[i]);
		}
		newenviron[i] = calloc(strlen(str_to_add), sizeof(char));
		strcpy(newenviron[i], str_to_add);
		environ = newenviron;
		free(str_to_add);
		return (0);
	}
	else
	{
		if (overwrite == 0)
		{
			free(str_to_add);
			return (0);
		}
		else
		{
			for (i = 0; i < envlen; i++)
			{
				if (environ[i] == match)
				{
					ptrlen = strlen(str_to_add);
					newenviron[i] = calloc(ptrlen, sizeof(char));
					strcpy(newenviron[i], str_to_add);
				}
				else
				{
					ptrlen = strlen(environ[i]);
					newenviron[i] = calloc(ptrlen, sizeof(char));
					strcpy(newenviron[i], environ[i]);
				}
				environ = newenviron;
				free(str_to_add);
				return (0);
			}
		}
	}
	return (0);
}
