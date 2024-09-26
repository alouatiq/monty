CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89
SRC = main.c push.c pall.c pint.c pop.c swap.c add.c nop.c  # List of all your .c files
OBJ = $(SRC:.c=.o)  # This will convert each .c file into its corresponding .o file

# The main target
all: monty

# Build the monty executable from object files
monty: $(OBJ)
	$(CC) $(CFLAGS) -o monty $(OBJ)

# Compile each .c file into .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove the executable and object files
clean:
	rm -f monty *.o
