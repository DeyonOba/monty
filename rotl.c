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
		int n = (*stack)->n;
		stack_t *current, *new;

		current = (*stack)->next;
		free(current->prev);
		current->prev = NULL;
		*stack = current;

		while (current->next != NULL)
		{
			current = current->next;
		}

		new = malloc(sizeof(stack_t));

		if (new == NULL)
		{
			fprintf(stderr, "memory allocation failed\n");
			free_resources();
			exit(EXIT_FAILURE);
		}

		new->n = n;
		new->prev = current;
		new->next = NULL;
		current->next = new;

	}
}
