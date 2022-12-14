#include "monty.h"

/**
 * Pint - prints the value at the top of the stack, followed by a new line
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Pint(stack_t **stk, unsigned int line_number)
{
	/* if stack is empty */
	if (L_EMPTY(stk))
		err_handler(ERR_SIE, "pint", line_number, 1);

	printf("%d\n", (*stk)->n);
}

/**
 * Pall - print all element in a stack | queue
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Pall(stack_t **stk, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr = NULL;

	if (L_EMPTY(stk))
		return;

	ptr = *stk;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * Swap - swap the top two element in linked list
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Swap(stack_t **stk, unsigned int line_number)
{
	stack_t *next;

	/* if number of nodes is less than 2 */
	if (!L_TW_NODES(stk))
		err_handler(ERR_SIS, "swap", line_number, 1);

	next = (*stk)->next;
	next->prev = (*stk)->prev;
	(*stk)->prev = next;
	(*stk)->next = next->next;
	/* if there are more than two nodes */
	if (next->next)
		next->next->prev = *stk;
	next->next = *stk;
	/*update head node */
	*stk = next;
}

/**
 * Add - Adds the top two element in linked list
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Add(stack_t **stk, unsigned int line_number)
{
	stack_t *next = NULL, *curr = NULL, *node = NULL;
	int num;

	/* if number of nodes is less than 2 */
	if (!L_TW_NODES(stk))
		err_handler(ERR_SIS, "add", line_number, 1);

	curr = *stk;
	/* make sure first node */
	while (curr)
	{
		if (!curr->prev)
			break;
		curr = curr->prev;
	}
	next = curr->next;
	/* get new node val */
	num = curr->n + next->n;
	/* remove first two nodes */
	rm_first_node(stk), rm_first_node(stk);
	/* add new node */
	node = add_to_node(stk, num);
	/* check node created */
	if (!node)
		fprintf(stderr, "Error: malloc failed"), free_m_buff(), exit(EXIT_FAILURE);
}

/**
 * Nop - does nothing
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Nop(__attribute__((unused)) stack_t **stk,
	__attribute__((unused)) unsigned int line_number)
{

}
