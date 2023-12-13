#include "main.h"

/**
 * bigi_pint - THis is a function that prints the topmost value of a stack
 * @stack: The stack of doubly linked list
 * @line_num: This is the line number of command for error messae printing
 * Return: Nothing for a void function
 */

void bigi_pint(unsigned int line_num, **stack)
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

