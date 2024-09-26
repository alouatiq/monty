#include <stdio.h>   /* For FILE, fprintf, fopen, stderr, fclose */
#include <stdlib.h>  /* For exit, EXIT_FAILURE */
#include <string.h>  /* For strtok */
#include "monty.h"   /* For custom functions and stack_t */

void process_line(char *line, unsigned int line_number, stack_t **stack);
int is_number(char *str);  /* Declare is_number function */

/**
 * main - Entry point of the Monty bytecode interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;  /* Initialize stack to NULL */

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read file line by line using fgets, as getline is not available in C89 */
    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        printf("Reading line %d: %s", line_number, line);  /* Debugging output */
        process_line(line, line_number, &stack);
    }

    free(line);
    fclose(file);
    return (0);
}

/**
 * process_line - Parses a line and executes the corresponding opcode.
 * @line: The line from the bytecode file.
 * @line_number: The current line number.
 * @stack: Pointer to the top of the stack.
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
    char *opcode;
    int n;

    opcode = strtok(line, " \n\t");
    if (!opcode || opcode[0] == '#')  /* Ignore empty lines and comments */
        return;

    printf("Processing opcode: %s (line %d)\n", opcode, line_number);  /* Debug */

    if (strcmp(opcode, "push") == 0)
    {
        char *arg = strtok(NULL, " \n\t");

        if (!arg || !is_number(arg))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        n = atoi(arg);  /* Convert argument to an integer */
        printf("Pushing value: %d\n", n);  /* Debug */
        push(stack, line_number, n);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        printf("Executing pall (line %d)\n", line_number);  /* Debug */
        pall(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

/**
 * is_number - Checks if a string is a number.
 * @str: The string to check.
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_number(char *str)
{
    int i;

    if (str == NULL || *str == '\0')
        return (0);
    
    for (i = 0; str[i]; i++)  /* Declare i at the top of the block */
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }

    return (1);
}
