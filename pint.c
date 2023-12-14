#include "monty.h"

/**
 * pint - THis is a function that prints the topmost value of a stack
 * @stack: The stack of doubly linked list
 * @line_number: This is the line number of command for error messae printing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	else
		printf("%d\n", top->n);
}
