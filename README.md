SIMPLE SHELL
============

simple UNIX command interpreter.


## Environment
built and tested in the Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC version 4.8.4

## Contains:
Simple Shell files:

| **File** | **Description** |
|----------|-----------------|
| xxxxxx | xxxxxxxx |
| xxxxxx | xxxxxxxxxx |


## Installation:
Clone the repo:
```

```

## Compile it:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
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
* [**Hernan Dario Castano**](https://github.com/dario-castano)
* [**Thomas Montoya**](https://github.com/thomasmontoya123)

-----
