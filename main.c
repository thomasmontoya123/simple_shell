#include "shell_header.h"

/**
 * main - Entry point
 *
 * Return: always 0
 */

int main(void)
{
	char *input_line, **arguments;
	int status = 1;

	do {

		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);

		input_line = line_reader();
		arguments = line_spliter(input_line);
		status = executer(arguments);
		free(input_line);
		free(arguments);

	} while (status);

	return (0);
}
