#include <signal.h>
#include "shell_header.h"
#include "signal_handling.h"
#include "pathmgmt.h"

/**
 * main - Entry point
 *
 * @argc: argument counter
 * @argv: argument value
 * @envp: environmet variables
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

	setenv("OLDPWD", _getenv("PWD"), 1);
	setenv("TERM", "xterm-256color", 1);

	do {

		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);


		input_line = _getline();
		arguments = line_spliter(input_line);
		status = launcher(arguments, envp);
		free(input_line);
		free(arguments);

	} while (status);

	return (0);
}
