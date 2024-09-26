#include "monty.h"

/**
	* swap - Swaps the top two elements of the stack.
	* @stack: Double pointer to the top of the stack.
	* @line_number: The current line number in the bytecode file.
	*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!*stack || !(*stack)->next)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	if (second->next)
	second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}
