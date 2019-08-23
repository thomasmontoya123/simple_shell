#include "shell_header.h"

/**
 * main - Entry point
 *
 * Return: always 0
 */

int main(int argc, char *argv[], char *envp[])
{
	char *inputLine, **arguments;
	int status = 1;

	(void) argc;
	(void) argv;


	do {

		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);

		inputLine = _getline();
		arguments = line_spliter(inputLine);
		status = launcher(arguments, envp);
		free(inputLine);
		free(arguments);

	} while (status);

	return (0);
}
