#include "shell_header.h"

/**
 * help - print shell help
 * @arguments: arguments
 *
 * Return: void
 */

int help(__attribute__((unused)) char **arguments)
{
	write(1, "here goes the shell help\n", 26);
	return (1);
}
