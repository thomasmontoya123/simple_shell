#include "shell_header.h"

/**
 * help - print shell help
 * @arguments: arguments
 *
 * Return: void
 */

int help(__attribute__((unused)) char **arguments)
{
	if (!arguments[1])
	{
		write(1, "help without args\n", 19);
		return (1);
	}

	else if (_strcmp(arguments[1], "cd") == 0)
	{
		write(1, "help cd\n", 9);
		return (1);
	}

	else if (_strcmp(arguments[1], "env") == 0)
	{
		write(1, "help env\n", 10);
		return (1);
	}

	else if (_strcmp(arguments[1], "exit") == 0)
	{
		write(1, "help exit\n", 11);
		return (1);
	}

	return (1);
}
