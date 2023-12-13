#include "main.h"

/**
 * bigi_pall - THis is a function that is use to print the element of a stack
 * @stack: This is a stack of a doubly linked list
 * @line_num: The line number of the command for printing error message 
 * Return: Void
 */

void bigi_pall(stack_t **stack)
{
	stack_t *array = NULL;

	array = *stack;
	if (*array != NULL)
	{
		printf("%d\n", array->n);
		array = array->next;
	}
}
