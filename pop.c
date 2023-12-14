#include "monty.h"

/**
 * pop - This function removes the topmost element of a stack
 * @line_num: THis is the line number of commands for printing error messages
 * @stack: This is the stack of a doubly linked list
 * Return: Nothing
 */

void pop(stack_t *stack[], unsigned int line_num)
{
	stack_t *top; /**Initailizes top as an element of a stack**/

	if (*stack == NULL) /**Test if their is no element in the stack**/
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_resources();
		exit(EXIT_FAILURE);
	}

	top = *stack; /** Initailizes topmost element of the stack to var top**/
	if (top->next != NULL) /**Test if the next element is not NULL**/
	{
		*stack = top->next;/**Move the stack to the next node**/
		(*stack)->prev = NULL;/**Update the prev stack**/
	}

	else
		*stack = NULL; /** Stack is NULL if it is the last element**/

	free(top); /** Free the memory allocated for topmost element**/
}
