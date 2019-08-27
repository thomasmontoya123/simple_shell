#include "shell_header.h"

/**
 * _getchar - reads character
 *
 * Return: one char for each call
 */

int _getchar(void)
{
	char *character, buffer[1];
	int read_descriptor = 0;

	read_descriptor = read(STDIN_FILENO, buffer, 1);

	if (read_descriptor > 0)
	{
		character = buffer;
		return (*character);
	}

	else if (read_descriptor == -1)
	{
		perror("Error reading");
		return (0);
	}

	return (EOF);
}
