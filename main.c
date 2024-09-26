#include <stdio.h>   // For FILE, fprintf, fopen, stderr, fclose
#include <stdlib.h>  // For exit, EXIT_FAILURE
#include "monty.h"   // For custom functions and stack_t

int main(int argc, char **argv)
{
    FILE *file;  /* Declaration moved to the top */

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");  /* Now only the assignment happens here */
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Process the bytecode file */
    fclose(file);
    return (0);
}
