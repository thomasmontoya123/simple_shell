#ifndef _SHELL_HEADER_H_
#define _SHELL_HEADER_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * _getline(void);
char **line_spliter(char *inputLine);
int executer(char **arguments);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getchar(void);
unsigned int _strspn(char *s, const char *accept);
char *_strtok_mod (char *str, const char *delim, char **save_ptr);
char *_strtok(char *str, const char *delimiters);

#endif
