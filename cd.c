#include "shell_header.h"

/**
 * cd - chnge directory
 *
 * @arguments: arguments
 *
 * Return: 1
 */

int cd(char **arguments)
{

	char cwd[1024];
	int cwd_size, index;

	if (!arguments[1])
	chdir(getenv("HOME"));

	else if (_strcmp(arguments[1], "-") == 0)
	{
		if (getenv("OLDPWD") == NULL)
			chdir(".");

		else
		{
			chdir(getenv("OLDPWD"));

			getcwd(cwd, sizeof(cwd));

			for (cwd_size = 0; cwd[index] != '\0'; index++)
			cwd_size++;

			cwd[index] = '\n';

			write(1, cwd, cwd_size + 1);
		}
	}

	else
		chdir(arguments[1]);

	return (1);
}
