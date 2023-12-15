#include "monty.h"

/**
 * pstr - This is a function that prints string in a stack starting from the top
 * @stack: This is the pointer to the stack
 * @line_number: The line number of command for error message printing
 * Reurn: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *element;
	(void)line_number;

	element = *stack;

	while (element != NULL && element->n != 0 && element->n >= 0 && element->n <= 127)
	{
		printf("%c", (char)(element->n));
		element = element->next;
	}

	printf("\n");
}
