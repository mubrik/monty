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
	stack_t *node = NULL;
	int num = 0;

	if (!stk)
	{
		fprintf(stderr, "Initialize monthy data");
		exit(EXIT_FAILURE);
	}
	/* get num from monthy_data, atoi returns 0 on error*/
	if (monty_data.p_data[1])
		num = atoi(monty_data.p_data[1]);

	/* check if num actually a number or NULL */
	/* @smart cant push 0 to stack with this if check? */
	if (num == 0 || !num)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_m_buff();
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
	int ex_code;

	if (!stk || !(*stk))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_m_buff();
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
