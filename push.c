#include "main.h"

/**
 * push - Function adds element to the top of the stack
 *
 * @stack: Doubly linked list containing stack elements
 * @line_number: line number in the bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value;
	int num;
	stack_t *new_node = NULL;

	value = strtok(NULL, " \t\n");

	if (!value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(value);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	*stack = new_node;
}
