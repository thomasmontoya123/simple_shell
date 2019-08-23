#include "shell_header.h"
#include "pathmgmt.h"
#include <errno.h>

/**
 * executer  - handle the procces and execution
 *
 * @arguments: arguments to execute
 *
 * Return: 1 if succes (status);
 */


int executer(char **arguments)
{
	int status, exec_status;
	char *found_path;
	pid_t process_id;

	if (*arguments == NULL)
		return (1);

	process_id = fork();

	if (process_id == 0)
	{
		if (strchr(arguments[0], '/') != NULL)
		{
			exec_status = execve(arguments[0], arguments, NULL);
			if (exec_status == -1)
			{
				perror("Exec error");
				return (0);
			}
		}
		else
		{
			found_path = find_path(arguments[0]);
			if (found_path == NULL)
			{
				perror("Not found");
				return (0);
			}
			else
			{
				arguments[0] = found_path;
				exec_status = execve(arguments[0], arguments, NULL);
					if (exec_status == -1)
					{
						free(found_path);
						perror("Exec error");
						return (0);
					}
				free(found_path);
				return (0);
			}
		}
	}

	else if (process_id < 0)
		perror("Fork failure");
	else
		wait(&status);

	return (1);
}
