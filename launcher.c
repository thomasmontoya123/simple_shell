#include "shell_header.h"

/**
 * launcher - check for builtins and execute.
 * @arguments: arguments
 * @environment: env variables.
 * Return: depends on executer.
 */

static char *builtin_name[] = {"cd", "help", "env", "exit"};
static int number_of_builtins = 4;

int (*builtin_function[]) (char **) = {&cd, &help, &environment_builtin,
&exit_builtin};

int launcher(char **arguments, char **environment)
{
	int index, exit_return = 0;
	int exit_argument = 0;

	for (index = 0; index < number_of_builtins; index++)
	{
		if (_strcmp(arguments[0], "env") == 0)
			return (environment_builtin(environment));

		if (_strcmp(arguments[0], "exit") == 0)
		{
			exit_return = exit_builtin(arguments);
			exit_argument = _atoi(arguments[1]);
			if (exit_argument < 0)
			{
				write(1, "exit: illegal number: ", 23);
				exit(EXIT_FAILURE);
			}
			if (exit_return == -1)
				perror("Error on exit");

			else
			{
				free(arguments);
				exit(exit_return);
			}
		}
		if (_strcmp(arguments[0], builtin_name[index]) == 0)
		{
			return ((*builtin_function[index])(arguments));
		}
	}
	return (executer(arguments));
}
