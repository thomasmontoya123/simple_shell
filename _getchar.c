#include "shell_header.h"

/**
 * _getchar - reads character
 *
 * Return: one char for each call
 */

int _getchar(void)
{
	char buffer[1024];
	static int  first, last;
	int ascii_character = 0;



	if (first == last)
	{
		ascii_character = read(0, buffer, 1024);
		if (ascii_character == 0)
			return (EOF);

	last = ascii_character;
	first = 0;

	}


	if (ascii_character >= 0)
		return (buffer[first++]);

	return (EOF);
}
