#include <signal.h>
#include "shell_header.h"
#include "signal_handling.h"

/**
 * main - Entry point
 *
 * Return: always 0
 */

int main(int argc, char *argv[], char *envp[])
{
	char *input_line, **arguments;
	int status = 1;

	(void) argc;
	(void) argv;

	signal(SIGINT, blank);

	do {

		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);

		input_line = line_reader();
		arguments = line_spliter(input_line);
		status = launcher(arguments, envp);
		free(input_line);
		free(arguments);

	} while (status);

	return (0);
}
