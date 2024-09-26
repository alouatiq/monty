#include "monty.h"

/**
	* rotr - Rotates the stack to the bottom.
	* @stack: Double pointer to the top of the stack.
	* @line_number: The current line number (unused).
	*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	return;

	tail = *stack;

	while (tail->next)  /* Traverse to the last node */
	tail = tail->next;

	tail->prev->next = NULL;  /* Unlink the last node from the list */
	tail->prev = NULL;
	tail->next = *stack;  /* Move the last node to the top */
	(*stack)->prev = tail;
	*stack = tail;
}
