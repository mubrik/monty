#include "monty.h"

/**
 * Peek - gets the top item on the stack
 * @top: ptr to current top to allow mutation
 * @head: head of malloc'd memory
 * @return *id_name_t or NULL
 * Return: *id_name_t
 */
id_name_t *Peek(stk_t *stk)
{
	id_name_t *node = NULL;

	if (!stk || is_empty(stk->top))
		return (node);

	node = stk->head[stk->top];
	if (!node)
		return (NULL);

	return (node);
}

/**
 * Free - free's up a malloc'd stack
 * @top: ptr to current top to allow mutation
 * @head: head of malloc'd memory
 * @return void
 * Return: void
 */
void Free(stk_t *stk)
{
	id_name_t *node;
	/* while stack not empty */
	while (!is_empty(stk->top))
	{
		/* get a nde and free it */
		node = Pop(stk);
		free(node);
	}
	/* free final alloc */
	free(stk->head);
}

/**
 * test_stack - test_stack function
 * Return: int
 */
int test_stack(void)
{
	/* top to track stack index */
	int index;
	id_name_t **stack_head;
	id_name_t *node;
	stk_t stk_holder;

	/* create head for stack */
	stack_head = malloc(sizeof(id_name_t *) * STACK_SIZE);
	if (!stack_head)
		return (1);
	/* keep stack data in struct for easy organise */
	stk_holder.head = stack_head;
	stk_holder.top = -1;

	/* perform some operation, check mpty */
	printf("Stack is %s \n", is_empty(stk_holder.top) ? "Empty" : "Not empty");
	/* push items */
	Push(&stk_holder, "0", "Mubrik"), printf("Adding to stack\n");
	Push(&stk_holder, "1", "User"), printf("Adding to stack\n");
	Push(&stk_holder, "2", "Admin"), printf("Adding to stack\n");
	Push(&stk_holder, "3", "ALX"), printf("Adding to stack\n");
	/* chcek empty */
	printf("Stack is %s \n", is_empty(stk_holder.top) ? "Empty" : "Not empty");
	/* len */
	printf("Length of stack %d \n", stk_holder.top);
	/* check top item */
	node = Peek(&stk_holder);
	if (node)
		printf("Top item in stack id: %s name: %s \n", node->id, node->name);
	/* Pop a couple and peek, freeing immediately */
	free(Pop(&stk_holder)); /* pop ALX */
	free(Pop(&stk_holder)); /* pop Admin */
	/* check top item */
	node = Peek(&stk_holder);
	if (node)
		printf("Top item in stack id: %s name: %s \n", node->id, node->name);
	/* len */
	printf("Length of stack %d \n", stk_holder.top);
	/* perform some operation, check mpty */
	printf("Stack is %s \n", is_full(stk_holder.top) ? "Full" : "Not full");
	/* fill it up */
	for (index = 0; index < STACK_SIZE; index++)
		Push(&stk_holder, "8", "fill");
	/* check full */
	printf("Stack is %s \n", is_full(stk_holder.top) ? "Full" : "Not full");
	/* len */
	printf("Length of stack %d \n", stk_holder.top);
	/* free stack */
	Free(&stk_holder);
	return (0);
}
