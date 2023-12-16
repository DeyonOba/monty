#include "monty.h"

/**
 * rotr - This is the fucntion that rotates the stack to the right
 * @stack: The pointer to the head of the stack
 * @line_number: Line number
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = *stack;
		(*stack)->prev = tmp;
		tmp = *stack;
		(*stack) = tmp->prev;
		(*stack)->prev = NULL;
		tmp->prev = NULL;
	}

	(void)line_number;
}
