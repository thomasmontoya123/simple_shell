#ifndef _SHELL_HEADER_H_
#define _SHELL_HEADER_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_MAX  2097152

extern char **environ;

char *line_reader(void);
char **line_spliter(char *inputLine);
int executer(char **arguments);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getchar(void);
unsigned int _strspn(char *s, const char *accept);
char *_strtok_mod(char *str, const char *delim, char **save_ptr);
char *_strtok(char *str, const char *delimiters);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
ssize_t _strcspn(const char *s, const char *reject);
int environment_builtin(char **environment);
int help(__attribute__((unused)) char **arguments);
int cd(char **arguments);
int exit_builtin(char **arguments);
int launcher(char **arguments, char **environment);
int _atoi(char *s);
char *_getline(void);
char *_strchr(const char *s, int c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif
