#include "monty.h"

/**
 * mul - Multiple the top element with the second element in the stack
 *
 * @stack: The pointer to the top of the stack
 * @line_number: File line number been executed
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
