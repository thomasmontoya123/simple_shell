#include "shell_header.h"

/**
 * line_reader - handle the input
 *
 * Return: the input  as a string
 */


char *line_reader(void)
{
	char *input_line = NULL;
	int line_checker;
	size_t bufer_size = 0;

	line_checker = getline(&input_line, &bufer_size, stdin);
	if (line_checker == EOF || line_checker == -1)
		exit(EXIT_FAILURE);

	return (input_line);
}
