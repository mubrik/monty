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
	long num = 0;
	buf endptr = NULL;

	/* get num from monthy_data, atoi returns 0 on error*/
	/* make sure p_data[1] is NULL if not given */
	if (monty_data.p_data[1] == NULL)
		err_handler(ERR_PBA, NULL, line_number, 1);
	/* using atoi, there is no way to distinguish between 0 as an error */
	/* and as the converted value. it is recommended to */
	/* instead use the strtol() function */
	else
		num = strtol(monty_data.p_data[1], &endptr, 10);
	/* check if num actually a number or NULL */
	if (endptr && *endptr != '\0')
		err_handler(ERR_PBA, NULL, line_number, 1);
	/* stack LIFO / Queue FIFO */
	if (monty_data.d_type)
		node = add_to_node_end(stk, num);
	else
		node = add_to_node(stk, num);
	/* check node created */
	if (!node)
		err_handler(ERR_MME, NULL, line_number, 1);

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

	if (L_EMPTY(stk))
		err_handler(ERR_PPS, NULL, line_number, 1);
	/* check LIFO/FIFO */
	if (monty_data.d_type == 0)
	{
		/* stack LIFO, remove last item */
		ex_code = rm_first_node(stk);
	}
	if (ex_code == 1)
	{
		/* stack not created yet, not sure how to handle this error */
		err_handler(ERR_PPS, NULL, line_number, 1);
	}
}
