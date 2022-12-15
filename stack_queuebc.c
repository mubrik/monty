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
