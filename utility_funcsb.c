#include "monty.h"
#include <ctype.h>

/**
 * get_func - returns the correct function for a opcode
 * @opcode: string representation of the operation
 *
 * Return: ptr stack or queue func operation or NULL
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int idx = 0;
	instruction_t arr_structs[] = {
		{ "pall", Pall }, { "push", Push },
		{ "pint", Pint }, { "pop", Pop },
		{ "swap", Swap }, { "add", Add }, { "rotr", Rotr },
		{ "nop", Nop }, { "#", Nop }, { "rotl", Rotl },
		{ "sub", Sub }, { "div", Div }, { "mod", Mod },
		{ "mul", Mul }, { "pchar", Pchar }, {"pstr", Pstr},
		{ "stack", Type }, { "queue", Type },
	};

	if (!opcode)
		return (NULL);

	while (idx <= INS_COUNT)
	{
		if (strcmp(arr_structs[idx].opcode, opcode) == 0)
			return (arr_structs[idx].f);
		idx++;
	}
	return (NULL);
}

/**
 * update_dtype - updates the global var from stack to queue, vise versa
 * @op: the structure to use -> "stack" or "queue"
 * Return: nothing
 */
int update_dtype(char *op)
{
	int updated = 1;

	if (!op)
		return (0);

	if (strcmp(op, "stack") == 0)
		monty_data.d_type = 0;
	else if (strcmp(op, "queue") == 0)
		monty_data.d_type = 1;
	else
		updated = 0;

	return (updated);
}

/**
 * Tokenize - split a string into tokens
 * @str: original string
 *
 * Return: array of tokens/strings
 */
void Tokenize(char *str)
{
	int idx = 0;
	char *token;
	const char *seperators = " \n\t";
	/* set defaults */
	monty_data.p_data[idx] = NULL;
	monty_data.p_data[idx + 1] = NULL;
	/* get first */
	token = strtok(str, seperators);
	/* basic check for comment */
	if (idx == 0 && token && token[0] == '#')
	{
		/* add null byte and set in monty data */
		if (token[1])
			token[1] = '\0';
		monty_data.p_data[idx] = token;
		return;
	}
	/* first opcode */
	if (token)
		monty_data.p_data[idx] = token;
	/* 2nd for push opcode exclusively */
	token = strtok(NULL, seperators);
	if (token)
		monty_data.p_data[idx + 1] = token;
}

/**
 * free_m_buff - utility function to easily free up malloc'd buffers in m_data
 * Return: void
 */
void free_m_buff(void)
{
	/* check line buff and free */
	if (monty_data.line_buf)
		free(monty_data.line_buf);

	/* check linked list head */
	if (monty_data.stk_head)
		free_stk_list(&monty_data.stk_head);

	/* check if file stream open */
	if (monty_data.file)
		fclose(monty_data.file);
}

/**
 * err_handler - handles monty_p errors
 * @err: the error flag, check header for enum
 * @str: the string to use when available, can be NULL
 * @line_num: the line number
 * @ex_code: to check if to exit program or not
 * Return: int
 */
void err_handler(enum error_type err, char *str,
	unsigned int line_num, int ex_code)
{
	switch (err)
	{
	case ERR_ANF:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case ERR_FNF:
		fprintf(stderr, "Error: Can't open file %s\n", str);
		break;
	case ERR_INF:
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
		break;
	case ERR_SIE:
		fprintf(stderr, "L%d: can't %s, stack empty\n", line_num, str);
		break;
	case ERR_SIS:
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, str);
		break;
	case ERR_PBA:
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		break;
	case ERR_PPS:
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		break;
	case ERR_MME:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	default:
		break;
	}
	/* check if to exit program */
	if (ex_code)
	{
		/*  free buf and exit */
		free_m_buff();
		exit(EXIT_FAILURE);
	}
}
