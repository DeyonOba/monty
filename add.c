#include "main.h"

/**
 * bigi_add - This is the function that add top two element in a stack
 * @stack: The pointer to the top of the stack
 * @line_num: The line of the command for err printing
 * Return: Void
 */

void bigi_add(unsigned int line_num, stack_t **stack)
{
	if (!stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	bigi_pop(stack, line_num);
}