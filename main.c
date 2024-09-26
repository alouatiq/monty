#include <stdio.h>   /* For FILE, fprintf, fopen, stderr, fclose */
#include <stdlib.h>  /* For exit, EXIT_FAILURE */
#include <string.h>  /* For strtok */
#include "monty.h"   /* For custom functions and stack_t */

/*
 * main.c - Entry point for the Monty bytecode interpreter.
 * Processes bytecode files and executes stack operations.
 */

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
    char line[1024];  /* Buffer to store each line */
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

    /* Read file line by line using fgets */
    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        process_line(line, line_number, &stack);
    }

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
    if (!opcode || opcode[0] == '#')  /* Ignore comments and empty lines */
        return;

    if (strcmp(opcode, "push") == 0)
    {
        char *arg = strtok(NULL, " \n\t");

        if (!arg || !is_number(arg))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        n = atoi(arg);  /* Convert argument to an integer */
        push(stack, line_number, n);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(stack, line_number);
    }
    else if (strcmp(opcode, "sub") == 0)
    {
        sub(stack, line_number);
    }
    else if (strcmp(opcode, "div") == 0)
    {
        div_op(stack, line_number);
    }
    else if (strcmp(opcode, "mul") == 0)
    {
        mul(stack, line_number);
    }
    else if (strcmp(opcode, "mod") == 0)
    {
        mod(stack, line_number);
    }
    else if (strcmp(opcode, "pchar") == 0)
    {
        pchar(stack, line_number);
    }
    else if (strcmp(opcode, "pstr") == 0)
    {
        pstr(stack, line_number);
    }
    else if (strcmp(opcode, "rotl") == 0)
    {
        rotl(stack, line_number);
    }
    else if (strcmp(opcode, "rotr") == 0)
    {
        rotr(stack, line_number);
    }
    else if (strcmp(opcode, "stack") == 0)
    {
        stack_op(stack, line_number);
    }
    else if (strcmp(opcode, "queue") == 0)
    {
        queue_op(stack, line_number);
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
    int i = 0;

    if (str == NULL || *str == '\0')
        return (0);

    if (str[0] == '-')  /* Handle negative numbers */
        i++;

    for (; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }

    return (1);
}
