#include "shell_header.h"

/**
 * main - Entry point
 * Return: always 0
 */

int main(void)
{
	char *inputLine, **arguments;
	int status = 1;

	do{

		if (isatty(STDIN_FILENO))
			write (1, "($) ", 4);

		inputLine = line_reader();
		arguments = line_spliter(inputLine);
		status = executer(arguments);
		free(inputLine);
		free(arguments);

	} while (status);

	return (0);
}
