#include "monty.h"

/**
 * list_has_2_nodes - wrapper func, if a stack_t list has 2 nodes.
 * @head: pto to head ptr to list first elem
 *
 * Return: 1 if list has 2 0 else
 */
int list_has_2_nodes(stack_t **head)
{
	if (!head || !(*head) || !(*head)->next)
		return (0);
	return (1);
}
