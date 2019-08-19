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
	pid_t process_id;

	if (*arguments == NULL)
		return (1);

	process_id = fork();

	if (process_id == 0)
	{
		if (execvp(arguments[0], arguments) == -1)
		{
			perror("Error");
			return (0);
		}

		exit(EXIT_FAILURE);

	}

	else if (process_id < 0)
		perror("Error");

	else
		wait(&status);	

	return (1);	
}
