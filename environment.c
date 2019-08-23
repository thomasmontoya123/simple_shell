#include "shell_header.h"

/**
 * environment_builtin - print all environment variables
 *
 * @environment: variables
 *
 * Return: 1
 */


int environment_builtin(char **environment)
{
	unsigned int index;
	int environment_variable_len = 0;


	for (index = 0; environment[index] != NULL; index++)
	{
		environment_variable_len = _strlen(environment[index]);

		write(1, environment[index], environment_variable_len);

		write(1, "\n", 1);
	}

	return (1);
}
