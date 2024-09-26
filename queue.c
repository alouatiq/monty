#include "monty.h"

/**
	* queue_op - Sets the format to a queue (FIFO).
	* @stack: Double pointer to the top of the stack.
	* @line_number: The current line number (unused).
	*/
void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	is_stack = 0;  /* Switch to queue mode (FIFO) */
}
