#include "monty.h"

/**
 * Push - Adds an item to the stack
 * @stk: head node of list
 * @line_number: current line number in bytecode file
 *
 * Return: nothing
 */
void Push(stack_t **stk, unsigned int line_number)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc can't allocate memory");
		return;
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!(*head))
	{
		*head = new_node;
		return (*head);
	}

	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;

	return (new_node);	
}

/**
 * Pop - Pops the top item and return it
 * @top: ptr to current top to allow mutation
 * @head: head of malloc'd memory
 * @return *id_name_t or NULL
 * Return: *id_name_t
 */
void Pop(stack_t **stk, unsigned int lin_number)
{
	
	//id_name_t *node = NULL;
	//int top_c = stk->top;

	//if (!stk || is_empty(top_c))
//		return (NULL);
	/* get node */
	//node = stk->head[top_c];
	/* check valid */
	//if (!node)
	//	return (NULL);
	/* not sure if to free the item?, decrement top */
	//stk->top = top_c - 1;

	//return (node);
}
