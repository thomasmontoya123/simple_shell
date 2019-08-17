CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
TESTLIBS=`pkg-config --cflags --libs check`

compile: *.c *.h
	$(CC) $(CFLAGS) -o ./build/hsh *.c *.h

test: tests.c ../holberton.h ../*.c
	$(CC) -g -ggdb -o runtest ./test/tests.c *.h *.c $(TESTLIBS)
	./test/runtest

clean:
	rm ./build/*
	rm -f ./test/runtest

authors:
	bash ./scripts/generate_authors.sh