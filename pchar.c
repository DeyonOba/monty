#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 *
 * @stack: Doubly linked list for the stack
 * @line_number: Monty bytecode execution line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}

}
