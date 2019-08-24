CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
TESTLIBS=`pkg-config --cflags --libs check`
DBGFLAGS=-g -ggdb 

compile: *.c *.h
	mkdir -p ./build
	$(CC) $(CFLAGS) -o ./build/hsh *.c *.h

all: *.c *.h
	mkdir -p ./build
	$(CC) $(CFLAGS) $(DBGFLAGS) -o ./build/hsh *.c *.h

test: tests.c ../holberton.h ../*.c
	$(CC) -g -ggdb -o runtest ./test/tests.c *.h *.c $(TESTLIBS)
	./test/runtest

clean:
	rm -f ./build/*
	rm -f ./test/runtest

authors:
	bash ./scripts/generate_authors.sh

dbg: *.c *.h
	$(CC) -g -ggdb $(CFLAGS) -o ./build/hsh *.c *.h
	gdb ./build/hsh
