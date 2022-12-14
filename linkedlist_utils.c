#include "monty.h"

/**
 * add_to_node - adds a new node at the beginning of a stack_t list.
 * @head: pto to head ptr to list first elem
 * @n: n for new node
 *
 * Return: ptr to new node.
 */
stack_t *add_to_node(stack_t **head, const int n)
{
	stack_t *node;
	/* null chk */
	if (!head)
		return (NULL);
	/* alloc space */
	node = malloc(sizeof(stack_t));
	if (!node)
		return (NULL);
	/* make sure start of node, not necessary but alx gon alx */
	while (*head)
	{
		if (!((*head)->prev))
		{
			/* make curr head prev node our new node */
			(*head)->prev = node;
			break;
		}
		*head = (*head)->prev;
	}
	/* struct attribs, make new node next curr head */
	node->n = n, node->prev = NULL, node->next = *head;
	/* set new node to be head and return */
	*head = node;
	return (node);
}

/**
 * add_node_to_end - adds a new node at the end of a stack_t list.
 * @head: pto to head ptr to list first elem
 * @n: n for new node
 *
 * Return: ptr to new node.
 */
stack_t *add_to_node_end(stack_t **head, const int n)
{
	stack_t *node = NULL, *tmp = NULL;
	/* null chk */
	if (!head)
		return (NULL);
	/* alloc space */
	node = malloc(sizeof(stack_t));
	if (!node)
		return (NULL);
	/* get last node */
	if (*head)
	{
		tmp = *head;
		while (tmp)
		{
			if (!tmp->next)
				break;
			tmp = tmp->next;
		}
		/* point last node next to new node */
		tmp->next = node;
	}
	else
		*head = node;
	/* struct attribs, make new node prev last */
	node->n = n, node->prev = tmp, node->next = NULL;

	return (node);
}

/**
 * rm_last_node - removes last node of a stack_t list.
 * @head: pto to head ptr to list first elem
 * Return: ptr to new node.
 */
int *rm_last_node(stack_t **head)
{
	stack_t *node = NULL, *prev = NULL;
	/* null chk */
	if (!head)
		return (1);
	/* get last item */
	node = *head;
	/* quick check if list even exist */
	if (!node)
		return (0);
	while (node)
	{
		if (!node->next)
			break;
		node = node->next;
	}
	/* check if previous, derefrence it */
	prev = node->prev;
	if (prev)
		prev->next = NULL;
	/* isolated, free pointer */
	free(node);

	return (0);
}

/**
 * rm_first_node - removes first node of a stack_t list.
 * @head: pto to head ptr to list first elem
 * Return: ptr to new node.
 */
int *rm_first_node(stack_t **head)
{
	stack_t *node = NULL, *next = NULL;
	/* null chk */
	if (!head)
		return (1);
	/* get first item */
	node = *head;
	/* quick check if list even exist */
	if (!node)
		return (0);
	while (node)
	{
		if (!node->prev)
			break;
		node = node->prev;
	}
	/* check if next, set as new head and remove prvious*/
	next = node->next;
	if (next)
		next->prev = NULL, *head = next;
	/* isolated, free pointer */
	free(node);

	return (0);
}
