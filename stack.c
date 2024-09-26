#include "monty.h"

/**
 * stack_op - Sets the format to a stack (LIFO).
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number (unused).
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    is_stack = 1;  /* Switch to stack mode (LIFO) */
}
