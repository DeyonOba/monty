#include "monty.h"

/**
 * rotr - This is the fucntion that rotates the stack to the right
 * @stack: The pointer to the head of the stack
 * @line_number: Line number
 */
void rotr(stack_t **stack, unsigned int line_number)
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
/**
void rotr(stack_t **stack, unsigned int line_number)
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
		last_node->prev->next = NULL;
		(*stack)->prev = last_node;
		*stack = last_node;
		last_node->prev = NULL;
	}
}
**/
