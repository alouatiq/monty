#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current && current->n > 0 && current->n <= 127)
    {
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}
