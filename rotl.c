#include "monty.h"

/**
 * rotl - This is the function that rotates the stack to the top
 * @stack: This is a pointer to the top of the stack
 * @line_number: The line number of command to print error message
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "memory allocation failed\n");
		free_resources();
		exit(EXIT_FAILURE);
	}

	if (*stack != NULL && (*stack)->next != NULL)
	{
		int n = (*stack)->n;

		current = (*stack)->next;
		free(current->prev);
		current->prev = NULL;
		*stack = current;

		while (current->next != NULL)
		{
			current = current->next;
		}
		new->n = n;
		new->prev = current;
		new->next = NULL;
		current->next = new;

	}
	else if ((*stack)->next == NULL)
	{
		new->n = 0;
		new->prev = *stack;
		new->next = NULL;
		(*stack)->next = new;
		swap(stack, line_number);
	}
}
