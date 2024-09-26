#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    printf("Executing pall (line %d)\n", line_number);  /* Debugging output */

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
