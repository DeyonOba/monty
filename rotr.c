#include "monty.h"

/**
 * rotr - This is the fucntion that rotates the stack to the right
 * @stack: The pointer to the head of the stack
 * @line_number: Line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last_node = *stack;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}

		last_node->next = *stack;
		(*stack)->prev = last_node;
		last_node = *stack;
		(*stack) = last_node->prev;
		(*stack)->prev = NULL;
		last_node->prev = NULL;
	}
}
