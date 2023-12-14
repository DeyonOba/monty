#include "monty.h"

/**
 * add - This is the function that add top two element in a stack
 * @stack: The pointer to the top of the stack
 * @line_number: The line of the command for err printing
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
