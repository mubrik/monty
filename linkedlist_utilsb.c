#include "monty.h"

/**
 * get_first_node - gets the node at the beginning of a stack_t list.
 * @head: pto to head ptr to list first elem
 *
 * Return: ptr to new node.
 */
stack_t *get_first_node(stack_t **head)
{
	stack_t *node;

	/* null chk */
	if (!head)
		return (NULL);
	node = *head;
	/* make sure start of node, not necessary but alx gon alx */
	while (node)
	{
		if (!node->prev)
			break;
		node = node->prev;
	}

	return (node);
}

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

/**
 * list_is_empty - wrapper func, if a stack_t list is empty.
 * @head: pto to head ptr to list first elem
 *
 * Return: 1 if list empty 0 else
 */
int list_is_empty(stack_t **head)
{
	if (!head || !*head)
		return (1);
	return (0);
}

/**
 * print_stk_list - prints all the elements of a stack_t list..
 * @head: head ptr to list first elem
 * Return: list size .
 */
size_t print_stk_list(stack_t *head)
{
	size_t count = 0;
	stack_t *node;

	node = head;
	/* make sure start of node, not necessary but alx gon alx */
	while (node)
	{
		if (!node->prev)
			break;
		node = node->prev;
	}

	/* iterate */
	while (node)
	{
		printf("%d\n", node->n);
		/* push */
		node = node->next, count++;
	}

	return (count);
}
