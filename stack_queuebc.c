#include "monty.h"

/**
 * Pstr - prints the str starting at top element in linked list
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Pstr(stack_t **stk, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node = NULL;

	/* first node */
	node = get_first_node(stk);
	if (!node)
	{
		printf("\n"); /* empty stack */
		return;
	}
	/* iterate */
	while (node)
	{
		if (node->n == 0)
			break;
		if (!IS_ASCII(node->n))
			break;
		printf("%c", node->n);
		node = node->next;
	}
	/* last line */
	printf("\n");

}

/**
 * Rotl - rotates the stack to the top
 * @stk: head node
 * @line_number: line number in bytecode file
 *
 * Return: nothing
 */
void Rotl(stack_t **stk, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tail, *head, *next;

	tail = head = *stk;
	/* if stack is empty or only one element */
	if (!head || !head->next)
		return;
	next = (*stk)->next;
	/* get the last node in stack */
	while (tail->next)
		tail = tail->next;

	head->next->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	/* update head node */
	*stk = next;
}


/**
 * Rotr - rotates the stack to the top
 * @stk: head node
 * @line_number: line number in bytecode file
 *
 * Return: nothing
 */
void Rotr(stack_t **stk, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tail, *head;

	tail = head = *stk;
	/* if stack is empty or only one element */
	if (!head || !head->next)
		return;
	/* get the last node in stack */
	while (tail->next)
		tail = tail->next;

	tail->prev->next = NULL;
	head->prev = tail;
	tail->prev = NULL;
	tail->next = head;
	/* update head node */
	*stk = tail;
}
