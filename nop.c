#include "monty.h"

/**
 * nop - This is a function that do not do anythingbut required to be created
 * @stack: The pointer to the stack
 * @line_num: The number of the command line for err message printing
 * Return: NOthing
 */

void nop(stack_t **stack, unsigned int line_num)
{
	(void)**stack;
	(void)line_num;
}
