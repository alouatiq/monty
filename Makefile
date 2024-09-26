CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89
SRC = $(wildcard *.c)  # Automatically include all .c files in the current directory
OBJ = $(SRC:.c=.o)  # Convert all .c files to .o files

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
