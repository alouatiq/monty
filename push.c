#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the bytecode file.
 * @n: The integer to push onto the stack.
 */

void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new_node;  /* Move the declaration to the top */

	(void)line_number;  /* Mark line_number as unused for now */

	new_node = malloc(sizeof(stack_t));  /* Now the assignment */
	if (!new_node)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	(*stack)->prev = new_node;

	*stack = new_node;
}
