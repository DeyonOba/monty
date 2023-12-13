#include "main.h"

/** addd_stack - This is the function that add an element be pushed
 * @stack: This is the stack of doubly linked list
 * @present: The pointer to the new node
 * Return: Nothing
 */

void add_stack(stack_t **stack, stack_t *present)
{
	if (*stack)
	{
		present->next = *stack;
		(*stack)->prev = present;
	}

	*stack = present;


/**
 * bigi_push - This is a function that pushes an element to a atack
 * @line_num: THis is The command line number used to print error
 * Return: Nothing
 */

void bigi_push(unsigned int line_num, stack_t **stack)
{
	char *args;
	int num;
	stack_t *present = NULL;
	void(line_num);

	if (!args)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(args);
	present = new_node(num);

	if (present == NULL)
	{
		fprintf(stderr, "Error: creating a new node failed\n");
		exit(EXIT_FAILURE);
	}

	add_stack(stack, present);
}



/**
 * new_node - This is a function that crate a new stack node
 * @num: This is the value to put in the node
 * Return: A ointer to the new node
 */

stack_t *new_node(int num)
{
	stack_t *present;

	if (present == NULL)
	{
		return (NULL);
	}

	present->n = num;
	present->prev = NULL;
	present->next = NULL;

	return (present);
}
