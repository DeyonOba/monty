#include "monty.h"

/**
 * rotl - This is the function that rotates the stack to the top
 * @stack: This is a pointer to the top of the stack
 * @line_number: The line number of command to print error message
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack != NULL)
	{
		stack_t *top, *current;
		int stack_size = 1;
		
		top = *stack, current = *stack;
		while (current->next != NULL)
		{
			current = current->next;
			stack_size++;
		}

		current->next = top;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		top->prev = current;
		top->next = NULL;

	}
}
