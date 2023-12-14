#include "monty.h"

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

	if (!value || !is_int(value))
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

/**
 * pall - Display all elements in a stack from top to bottom
 *
 * @stack: Doubly linked list for the stack
 * @line_number: Bytecode file line number been executed
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *initial = *stack;/** Store a copy of stack to initial**/
	(void)line_number;

	while (initial != NULL)
	{
		printf("%d\n", initial->n);
		initial = initial->next;
	}
}


/**
 * is_int - This function checks oif a string is a valid int
 * @str: The string to be checked
 * Return: 1 if the string is valid, 0 otherwise
 */

int is_int(const char *str)
{
	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9') && *str != '-' && *str != '+')
		{
			return (0);
		}
		str++;
	}

	return (1);
}
