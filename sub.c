#include "monty.h"

/**
 * sub - Subtracts the top element from the second element in the stack
 *
 * @stack: The pointer to the top of the stack
 * @line_num: File line number been executed
 */

void sub(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_resources();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_num);
}
