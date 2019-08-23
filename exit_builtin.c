#include "shell_header.h"

/**
 * exit_builtin - exit
 *
 * @arguments: arguments
 *
 * Return: 1 if succes -1 if it fails
 */

int exit_builtin(char **arguments)
{
	int flag, i, number;

	flag = 0;
	number = 0;

	if (arguments[1] == NULL)
		exit(EXIT_SUCCESS);

	for (i = 0; arguments[1][i]; i++)
	{
		if ((arguments[1][i] >= '0' && arguments[1][i] <= '9')
		|| arguments[1][0] == '+')
		{
			flag = 1;

			if (arguments[1][i + 1] < '0' || arguments[1][i + 1] > '9')
				break;
		}

		else
			break;

		flag = 0;
	}

	if (flag == 1)
	{
		number = _atoi(arguments[1]);
		return (number);
	}
	return (-1);
}
