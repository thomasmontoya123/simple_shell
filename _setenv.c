#include "shell_header.h"

/**
* _setenv - Function to handle the setenv.
* @arg1: Name of the variable to be set.
* @arg2: Value for the variable.
* @new_envs: New environment variables array.
*/
void _setenv(char *arg1, char *arg2, char *new_envs[])
{
	char *new_var, var_to_set[BUF_MAX];
	short i = 0, j = 0;

	if (!arg1 || !arg2)
	{
		write(STDERR_FILENO, "setenv: parameters not found\n", 29);
		return;
	}

	_strcpy(var_to_set, arg1);
	_strcat(var_to_set, "=");

	while (environ[i] && _strncmp(environ[i], var_to_set, _strlen(var_to_set)))
		i++;

	_strcat(var_to_set, arg2);
	if (environ[i])
		_strcpy(environ[i], var_to_set);
	else
	{
		new_var = _calloc(150, sizeof(char));
		_strcpy(new_var, var_to_set);
		while (new_envs[j])
			j++;
		new_envs[j] = new_var;
		new_envs[j + 1] = NULL;
		environ[i++] = new_var;
		environ[i] = NULL;
	}
}
