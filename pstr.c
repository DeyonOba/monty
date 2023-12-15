#include "monty.h"

/**
 * pstr - This is a function that prints string in a stack starting from the top
 * @stack: This is the pointer to the stack
 * @line_number: The line number of command for error message printing
 * Reurn: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;
	(void)line_number;

	while (element != NULL && element->n != 0 && (element->n >= 32 && element->n <= 126))
	{
		printf("%c", element->n);
		element = element->next;
	}
	printf("\n");
}
