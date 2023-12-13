#include "main.h"

/**
 * bigi_nop - This is a function that do not do anythingbut required to be created
 * @stack: The pointer to the stack
 * @line_num: The number of the command line for err message printing
 * Return: NOthing
 */

void bigi_nop(unsigned int line_num, stack_t *stack)
{
	(void)**stack;
	(void)line_num;
}
