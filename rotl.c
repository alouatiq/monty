#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number (unused).
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack, *tail;

    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tail = *stack;

    while (tail->next)  /* Traverse to the last node */
        tail = tail->next;

    *stack = (*stack)->next;  /* Move the second element to the top */
    (*stack)->prev = NULL;

    temp->next = NULL;  /* Move the original top element to the end */
    temp->prev = tail;
    tail->next = temp;
}
