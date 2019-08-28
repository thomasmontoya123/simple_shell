#include "shell_header.h"
#include "pathmgmt.h"
#include <errno.h>

/**
 * set_fullpath - merge path+command to make an
 * absolute path
 *
 * @target: place where you are going to put the path
 * @path: path without command
 * @cmd: command you want to add
 *
 * Return: void
 */
void set_fullpath(char *target, char *path, char *cmd)
{
	strcat(target, path);
	strcat(target, "/");
	strcat(target, cmd);
}

/**
 * count_path_delims - count the number of dirs
 * inside the path
 *
 * @str: the full path variable
 *
 * Return: number of places in the path
 */
unsigned int count_path_delims(char *str)
{
	int i = 0;
	char *s = str;

	while (*s != '\0')
	{
		if (*s == ':')
			i++;
		s++;
	}
	return (i + 1);
}

/**
 * get_path - returns the env $PATH variable
 * fully tokenized
 *
 * Return: $PATH tokenized
 *
 * -->YOU MUST FREE AFTER USE!<--
 */
char **get_path(void)
{
	char **out;
	char *token;
	char *env_str;
	unsigned int i, path_len;

	env_str = _getenv("PATH");

	if (env_str == NULL)
		return (NULL);

	path_len = count_path_delims(env_str);
	out = _calloc(path_len + 1, sizeof(char *));

	if (out == NULL)
	{
		errno = ENOMEM;
		perror("Allocation failure");
		return (NULL);
	}

	token = strtok(env_str, ":");
	*out = token;

	for (i = 1; i < path_len; i++)
	{
		token = strtok(NULL, ":");
		*(out + i) = token;
	}

	*(out + i) = NULL;

	return (out);
}

/**
 * cmd_path - search for a command in a tokenized
 * $PATH
 *
 * @cmd: command you want to find
 * @path: a tokenized $PATH environment var
 *
 * Return: full path of the executable -> success
 * otherwise NULL
 *
 * -->YOU MUST FREE AFTER USE!<--
 */
char *cmd_path(char *cmd, char **path)
{
	int file_found;
	char *fullname;

	if (cmd == NULL || path == NULL)
		return (NULL);

	while (*path != NULL)
	{
		fullname = _calloc(_strlen(cmd) + _strlen(*path) + 2, sizeof(char));
		if (fullname == NULL)
		{
			errno = ENOMEM;
			perror("Allocation failure");
			return (NULL);
		}

		set_fullpath(fullname, *path, cmd);

		file_found = access(fullname, F_OK);
		if (file_found != -1)
			return (fullname);

		free(fullname);
		path++;
	}

	return (NULL);
}

/**
 * find_path - finds a command in system's $PATH
 *
 * @cmd: command to find
 *
 * Return: full path of the executable -> success
 * otherwise NULL
 *
 * -->YOU MUST FREE AFTER USE!<--
 */
char *find_path(char *cmd)
{
	char **env_path = get_path();
	char *out;

	out = cmd_path(cmd, env_path);

	free(env_path);
	return (out);
}

