SIMPLE SHELL
============

simple UNIX command interpreter.


## Environment
built and tested in the Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC version 4.8.4

## Contains:
Simple Shell files:

| **File** | **Description** |
|----------|-----------------|
| _atoi | Translates string into int |
| _calloc | allocates memory for an array, using malloc. |
| _getchar | reads and store one character |
| _getenv | gets the environment variable from the $path |
| _getline | gets the user input |
| _realloc | reallocates a memory block using malloc and free |
| _strchr | finds the pointer to the first occurrence of a character |
| _strcspn | count characters until the first occurrence of reject char happens |
| _strspn | gets the length of a prefix substring. |
| _strtok_mod | String to token with save pointer |
| .gitignore | Specifies intentionally untracked files to ignore |
| AUTHORS | Authors, generated by script |
| auxiliar_functions | _strcmp (compare two strings), _strlen (get the string length) |
| blank | Empty function to manage signals | 
| cd | chnge directory |
| environment_builtin | Print all environment variables |
| executer  | Handle the procces and execution |
| exit_builtin | Exit from the shell (handle arguments) |
| help | Handle the shell help and builtins help |
| launcher | Check for builtins and execute |
| LICENSE | TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION |
| line_spliter | Split the input string into tokens |
| main | Entry point |
| Makefile | Handle the compilation |
| man_1_simple_shell | Man page |
| pathmgmt | Handles the path |
| pathmgmt.h | Header for the path management | 
| runpath | Run a command found it the $PATH |
| shell_header | Main header |
| siganl_handling.h | Signals header |



## Installation:
Clone the repo:
```
git clone https://github.com/thomasmontoya123/simple_shell.git
```

## Compile it:
```
make compile
```

## Run test suite
```
make test
```

## Run in debug mode
```
make dbg
```

## Example output interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

## Example output non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```


## Authors
* [**Hernan Dario Castaño**](https://github.com/dario-castano)
* [**Thomas Montoya**](https://github.com/thomasmontoya123)

-----
