#include "monty.h"

/**
 * SEmpty - helper func checks if a stack is empty
 * @stk: stack head
 * @return 1 if empty, 0 else
 * Return: 1 if full, 0 else
 */
int SEmpty(stack_t **stk)
{
	if (!stk || !(*stk))
		return (1);
	return (0);
}

/**
 * SFull - checks if a stack is full
 * @stk: stack head
 * @return 1 if empty, 0 else
 * Return: 1 if full, 0 else
 */
int SFull(stack_t **stk)
{
	/* not necessary, leaving for now */
	if (!stk || !(*stk))
		return (1);
	return (0);
}


/**
 * is_empty - helper func checks if a stack is empty
 * @top: current top index of stack
 * @return 1 if empty, 0 else
 * Return: 1 if full, 0 else
 */
int is_empty(int top)
{
	if (top == -1)
		return (1);
	return (0);
}


/**
 * is_full - checks if a stack is full
 * @top: current top index of stack
 * @return 1 if full, 0 else
 * Return: 1 if full, 0 else
 */
int is_full(int top)
{
	if (top == (STACK_SIZE - 1))
		return (1);
	return (0);
}

/**
 * Push - Adds an item to the stack
 * @top: ptr to current top to allow mutation
 * @head: head of malloc'd memory
 * @id: string ptr
 * @name: string ptr
 * @return *id_name_t or NULL
 * Return: *id_name_t
 */
id_name_t *Push(stk_t *stk, char *id, char *name)
{
	id_name_t *node;
	int top_c;

	top_c = stk->top;
	if (!stk || !id || !name)
		return (NULL);
	if (is_full(top_c))
		return (NULL);
	/* increment top by one */
	top_c += 1;
	/* alloc node */
	node = malloc(sizeof(id_name_t));
	if (!node)
		return (NULL);
	/* node attribs */
	node->id = id, node->name = name;
	/* get stack ptr using index */
	stk->head[top_c] = node;
	/* increment top tracker */
	stk->top = top_c;
	/* return */
	return (node);
}

/**
 * Pop - Pops the top item and return it
 * @top: ptr to current top to allow mutation
 * @head: head of malloc'd memory
 * @return *id_name_t or NULL
 * Return: *id_name_t
 */
id_name_t *Pop(stk_t *stk)
{
	id_name_t *node = NULL;
	int top_c = stk->top;

	if (!stk || is_empty(top_c))
		return (NULL);
	/* get node */
	node = stk->head[top_c];
	/* check valid */
	if (!node)
		return (NULL);
	/* not sure if to free the item?, decrement top */
	stk->top = top_c - 1;

	return (node);
}
