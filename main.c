#include "shell_header.h"

/**
 * main - Entry point
 *
 * Return: void
 */

void  main(void)
{
	char *inputLine, **arguments;
	int status;

	do {

		printf("($)");
		inputLine = line_reader();
		arguments = line_spliter(inputLine);
		status = executer(arguments);
		free(inputLine);
		free(arguments);

	} while (status);
}
