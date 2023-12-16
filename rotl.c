#include "monty.h"

/**
 * rotl - This is the function that rotates the stack to the top
 * @stack: This is a pointer to the top of the stack
 * @line_number: The line number of command to print error message
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *current = *stack, *next = NULL, *prev = NULL;

		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
			next = current->next;
			current->next = prev;
			current->prev = next;
			prev = current;
			current = next;
		}
		*stack = prev;
	}
}
