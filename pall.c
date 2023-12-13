#include "main.h"

/**
 * pall - Display all elements in a stack from top to bottom
 *
 * @stack: Doubly linked list for the stack
 * @line_number: Bytecode file line number been executed
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack != NULL)
	{
		printf("%d\n", (**stack).n);
		*stack = (**stack).next;
	}
}
