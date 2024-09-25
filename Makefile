CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

all: monty

monty: *.c
    $(CC) $(CFLAGS) -o monty *.c

clean:
    rm -f monty
