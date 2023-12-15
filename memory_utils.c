#include "monty.h"

/**
 * free_list - Frees the doubly linked list
 *
 * @head: The top/head of the list
 */
void free_list(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
