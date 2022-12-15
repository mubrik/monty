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
	if (!(*stk))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stk)->n);
}

/**
 * Pall - print all element in a stack | queue
 * @stk: head node
 * @line_number: line_number in bytecode file
 *
 * Return: nothing
 */
void Pall(stack_t **stk,	__attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr = *stk;
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
	if (!(*stk) || !(*stk)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	next = (*stk)->next;
	next->prev = (*stk)->prev;
	(*stk)->prev = next;
	(*stk)->next = next->next;
	next->next->prev = *stk;
	next->next = *stk;
	/*update head node */
	*stk = next;
}
