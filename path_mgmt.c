#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void set_fullpath(char *target, char *path, char *cmd)
{
	strcat(target, path);
	strcat(target, "/");
	strcat(target, cmd);
}

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

char **get_path(void)
{
	char **out;
	char *token;
	char *env_str;
	unsigned int i, path_len;

	env_str = getenv("PATH");

	if (env_str == NULL)
		return (NULL);

	path_len = count_path_delims(env_str);
	out = calloc(path_len + 1 , sizeof(char *));

	if (out == NULL)
	{
		errno = ENOMEM;
		perror("ERROR");
		return (NULL);
	}

	token = strtok(env_str,":");
	*out = token;

	for (i = 1; i < path_len; i++)
	{
		token = strtok(NULL, ":");
		*(out + i) = token;
	}

	*(out + i) = NULL;

	return (out);
}

char *cmd_path(char *cmd, char **path)
{
	int file_found;
	char *fullname;

	if (cmd == NULL || path == NULL)
		return (NULL);

	while (*path != NULL)
	{
		fullname = calloc(strlen(cmd) + strlen(*path) + 2, sizeof(char));
		if (fullname == NULL)
		{
			errno = ENOMEM;
			return (NULL);
		}

		set_fullpath(fullname, *path, cmd);

		file_found = access(fullname, F_OK);
		if (file_found != -1)
			return (fullname);

		free(fullname);
		*path++;
	}

	return (NULL);
}

char *find_path(char *cmd)
{
	char **env_path = get_path();
	char *out;

	out = cmd_path(cmd, env_path);

	free(env_path);
	return (out);
}