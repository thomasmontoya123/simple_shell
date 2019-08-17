#ifndef _SHELL_HEADER_H_
#define _SHELL_HEADER_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *line_reader(void);

char **line_spliter(char *inputLine);

int executer(char **arguments);

#endif
