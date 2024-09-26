#include "monty.h"

/**
	* pall - Prints all the values on the stack, starting from the top.
	* @stack: Double pointer to the top of the stack.
	* @line_number: The current line number in the bytecode file.
	*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;  /* Move the declaration to the top */

	(void)line_number;  /* Mark line_number as unused for now */

	current = *stack;   /* Now assign current after the declaration */

	while (current)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
}
