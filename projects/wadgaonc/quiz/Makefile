CFLAGS := -Wall -fpic -coverage -lm -std=c99

all: testme.c
	gcc -o test testme.c $(CFLAGS)

test: all
	./test
