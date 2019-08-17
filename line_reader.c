#include "shell_header.h"

/**
 * line_reader - handle the input
 *
 * Return: the input  as a string
 */


char *line_reader(void)
{
	char *inputLine = NULL;
	int lineChecker;
	size_t buferSize = 0;


	lineChecker = getline(&inputLine, &buferSize, stdin);
	if (lineChecker == EOF || lineChecker == -1)
		exit(98);

	return (inputLine);
}
