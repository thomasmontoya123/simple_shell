#include "shell_header.h"

/**
 * main - Entry point
 *
 * Return: always 0
 */

int main(void)
{
	char *inputLine, **arguments;
	int status = 1;

<<<<<<< HEAD
	do{

		write (1, "($)", 3);
=======
	do {
		if (isatty(STDIN_FILENO))
			printf("($) ");
>>>>>>> 1318d60360f35bd08617305894d7bbe96dad2273
		inputLine = line_reader();
		arguments = line_spliter(inputLine);
		status = executer(arguments);
		free(inputLine);
		free(arguments);

	} while (status);

	return (0);
}
