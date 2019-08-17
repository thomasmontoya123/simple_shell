#include "shell_header.h"

/**
 * main - Entry point
 *
 * Return: always 0
 */

int  main(void)
{
	char *inputLine, **arguments;
	int status = 1;

	do {

		printf("($) ");
		inputLine = line_reader();
		arguments = line_spliter(inputLine);
		status = executer(arguments);
		free(inputLine);
		free(arguments);

	} while (status);


	return (0);
}
