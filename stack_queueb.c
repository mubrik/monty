#include "monty.h"

/**
 * Sub - subs the top two element in linked list
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Sub(stack_t **stk, unsigned int line_number)
{
	stack_t *next = NULL, *curr = NULL, *node = NULL;
	int num;

	/* if number of nodes is less than 2 */
	if (!L_TW_NODES(stk))
		err_handler(ERR_SIS, "sub", line_number, 1);

	curr = *stk;
	/* make sure first node */
	while (curr)
	{
		if (!curr->prev)
			break;
		curr = curr->prev;
	}
	next = curr->next;
	/* get new node val, abs? */
	num = next->n - curr->n;
	/* remove first two nodes */
	rm_first_node(stk), rm_first_node(stk);
	/* add new node */
	node = add_to_node(stk, num);
	/* check node created */
	if (!node)
		err_handler(ERR_MME, NULL, line_number, 1);
}

/**
 * Div - divides the top two element in linked list
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Div(stack_t **stk, unsigned int line_number)
{
	stack_t *next = NULL, *curr = NULL, *node = NULL;
	int num;

	/* if number of nodes is less than 2 */
	if (!L_TW_NODES(stk))
		err_handler(ERR_SIS, "div", line_number, 1);
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
	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_m_buff(), exit(EXIT_FAILURE);
	}
	num = next->n / curr->n;
	/* remove first two nodes */
	rm_first_node(stk), rm_first_node(stk);
	/* add new node */
	node = add_to_node(stk, num);
	/* check node created */
	if (!node)
		err_handler(ERR_MME, NULL, line_number, 1);
}

/**
 * Mul - multiplies the top two element in linked list
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Mul(stack_t **stk, unsigned int line_number)
{
	stack_t *next = NULL, *curr = NULL, *node = NULL;
	int num;

	/* if number of nodes is less than 2 */
	if (!L_TW_NODES(stk))
		err_handler(ERR_SIS, "mul", line_number, 1);
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
	num = (next->n * curr->n);
	/* remove first two nodes */
	rm_first_node(stk), rm_first_node(stk);
	/* add new node */
	node = add_to_node(stk, num);
	/* check node created */
	if (!node)
		err_handler(ERR_MME, NULL, line_number, 1);
}

/**
 * Mod - mods the top two element in linked list
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Mod(stack_t **stk, unsigned int line_number)
{
	stack_t *next = NULL, *curr = NULL, *node = NULL;
	int num;

	/* if number of nodes is less than 2 */
	if (!L_TW_NODES(stk))
		err_handler(ERR_SIS, "mod", line_number, 1);
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
	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_m_buff(), exit(EXIT_FAILURE);
	}
	num = (next->n % curr->n);
	/* remove first two nodes */
	rm_first_node(stk), rm_first_node(stk);
	/* add new node */
	node = add_to_node(stk, num);
	/* check node created */
	if (!node)
		err_handler(ERR_MME, NULL, line_number, 1);
}

/**
 * Pchar - prints the char at top element in linked list
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Pchar(stack_t **stk, unsigned int line_number)
{
	stack_t *node = NULL;
	/* safe fucntion, return null if stk null */
	node = get_first_node(stk);
	if (!node)
		err_handler(ERR_SIE, "pchar", line_number, 1);
	if (IS_ASCII(node->n))
		printf("%c\n", node->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_m_buff();
		exit(EXIT_FAILURE);
	}
}
