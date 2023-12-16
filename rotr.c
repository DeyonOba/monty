#include "monty.h"

/**
 * rotr - This is the fucntion that rotates the stack to the right
 * @stack: The pointer to the head of the stack
 * @line_number: Line number
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL)
	{
		stack_t *last_node = *stack;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}

		last_node->next = *stack;
		(*stack)->prev = last_node;
		*stack = last_node;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
