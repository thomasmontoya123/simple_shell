#ifndef PATHMGMT_H_
#define PATHMGMT_H_

void set_fullpath(char *target, char *path, char *cmd);
unsigned int count_path_delims(char *str);
char **get_path(void);
char *cmd_path(char *cmd, char **path);
char *find_path(char *cmd);

#endif