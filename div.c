#include "monty.h"

/**
	* div - Divides the second top element of the stack by the top element.
	* @stack: Double pointer to the top of the stack.
	* @line_number: The line number in the file.
	*/
void div_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;  /* Divide the second top element by the top element */
	pop(stack, line_number);  /* Remove the top element */
}
