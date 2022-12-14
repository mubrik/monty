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
	stack_t *node;
	int num;

	if (!stk)
	{
		fprintf(stderr, "Initialize monthy data");
		exit(EXIT_FAILURE);
	}
	/* get num from monthy d */
	num = atoi(monty_data.p_data[1]);
	/* check if num actually a number */
	if (!(num >= 0 && num <= 9))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* stack LIFO / Queue FIFO */
	if (monty_data.d_type)
		node = add_to_node_end(stk, num);
	else
		node = add_to_node(stk, num);
	/* check node created */
	if (!node)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);

}


/**
 * Pop - Pops an item from the stack
 * @stk: head node of list
 * @line_number: current line number in bytecode file
 *
 * Return: nothing
 */
void Pop(stack_t **stk, unsigned int line_number)
{
	stack_t *node, *prev, *next;
	int ex_code;

	if (!stk || !(*stk))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* check LIFO/FIFO */
	if (monty_data.d_type == 0)
	{
		/* stack LIFO, remove last item */
		ex_code = rm_first_node(stk);
	}
	else
	{
		/* queue FIFO, remove first item */
		ex_code = rm_last_node(stk);
	}
	if (ex_code == 1)
	{
		/* stack not created yet, not sure how to handle this error */
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	}
}
