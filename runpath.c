#include "shell_header.h"
#include "pathmgmt.h"
#include <errno.h>

/**
 * runpath - run a command found it the $PATH
 * 
 * @arguments: argument vector
 * 
 * Return: status for main loop
 */
int runpath(char **arguments)
{
	char *found_path;
	int exec_status;

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