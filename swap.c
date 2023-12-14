#include "monty.h"

/**
 * swap - This is the function thaa swaps the top two element of a stack
 * @stack: The double pointer to the stack
 * @line_num: The line number of the command that is used to print err message
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_num)
{
	int temp_val;

	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp_val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_val;
}
