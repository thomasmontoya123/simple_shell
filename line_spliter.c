#include "shell_header.h"

/**
 * line_spliter - split the input string into tokens
 *
 * @inputLine: input string
 *
 * Return:addres of substrings
 */


char **line_spliter(char *inputLine)
{
	char *token, **tokens;
	int index = 0;
	const char tokenDelimiter[] = {" \n\r\t\a"};

	tokens = _calloc(98, sizeof(char *));

	if (!tokens)
		return (NULL);


	token = _strtok(inputLine, tokenDelimiter);

	while (token != NULL)
	{
		tokens[index] = token;
		token = _strtok(NULL, tokenDelimiter);
		index++;
	}

	tokens[index] = NULL;

	return (tokens);
}
