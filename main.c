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

    /* Read the file line by line using fgets */
    /* as getline is not available in C89 */
    while (fgets(line, len, file) != NULL)
    {
        line_number++;
        printf("Reading line %d: %s", line_number, line);  /* Debugging output */
        process_line(line, line_number, &stack);
    }

    free(line);
    fclose(file);
    return (0);
}
