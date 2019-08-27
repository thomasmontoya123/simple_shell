#include "shell_header.h"
#include "pathmgmt.h"

/**
 * cd - chnge directory
 *
 * @arguments: arguments
 *
 * Return: 1
 */

int cd(char **arguments)
{

	char pwd_update[1024], cwd[1024];
	int index;
	int cwd_size = 0;

	if (!arguments[1] || (arguments[1][0] == '~' && !arguments[1][1]))
		chdir(getenv("HOME"));

	else if (arguments[1][0] == '-' && !arguments[1][1])
	{
		chdir(getenv("OLDPWD"));
		getcwd(cwd, sizeof(cwd));
		for (index = 0; cwd[index] != '\0'; index++)
			cwd_size++;

		cwd[index] = '\n';
		write(1, cwd, cwd_size + 1);
	}

	else if (access(arguments[1], F_OK) == 0)
	{
		if (access(arguments[1], R_OK) != 0)
			write(1, "You do not have the permisions\n", 32);

		else
			chdir(arguments[1]);
	}

	else
		write(1, "Could not find the directory\n", 30);

	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", getcwd(pwd_update, sizeof(pwd_update)), 1);

	return (1);
}
