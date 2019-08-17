#include "shell_header.h"

/**
 * executer  - handle the procces and execution
 *
 * @arguments: arguments to execute
 *
 * Return: 1 if succes (status);
 */


int executer(char **arguments)
{
	int status;
	pid_t proccessId;


	proccessId = fork();

	if (proccessId == 0)
	{
		if (execve(arguments[0], arguments, NULL) == -1)
		{
			perror("Error");
			return (0);
		}

		exit(EXIT_FAILURE);

	}

	else if (proccessId < 0)
		perror("Error");

	else
		wait(&status);



	return (1);
}
