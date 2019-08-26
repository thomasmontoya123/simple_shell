
#include "shell_header.h"

/**
 * _getline - get the user input
 *
 * Return: pointer to the input line
 */

char *_getline(void)
{
	char *input_line;
	int ascii_character, index, buffer_size;

	index = 0;
	buffer_size = BUF_MAX;
	input_line = NULL;
	input_line = _calloc(buffer_size, sizeof(char));
	if (!input_line)
	{
		perror("Calloc fails\n");
		return (NULL);
	}
	while (1)
	{
		ascii_character = getchar();
		if (ascii_character == EOF)
		{
			free(input_line);
			exit(EXIT_FAILURE);
		}
		else if (ascii_character == '\n')
		{
			input_line[index] = '\0';
			return (input_line);
		}
		else
			input_line[index] = ascii_character;
		index++;
		if (index >= (buffer_size - 1))
		{
			buffer_size += 100;
			input_line = _realloc(input_line, buffer_size, buffer_size);
			if (!input_line)
			{
				perror("Realloc fails\n");
				free(input_line);
				exit(EXIT_FAILURE);
			}
		}
	}
}
