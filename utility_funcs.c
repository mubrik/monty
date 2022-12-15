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
		{ "pall", Pall },
		{ "push", Push },
		{ "pint", Pint },
		{ "pop", Pop },
		{ "swap", Swap },
		{ "add", Add },
		{ "nop", Nop },
		{ "#", Nop },
		{ "sub", Sub },
		{ "div", Div },
		{ "mod", Mod },
		{ "mul", Mul },
	};

	while (idx < 11)
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
 *
 * Return: nothing
 */
void update_dtype(char *op)
{
	if (strcmp(op, "stack") == 0)
		monty_data.d_type = 0;
	else if (strcmp(op, "queue") == 0)
		monty_data.d_type = 1;
}

/**
 * TrimWhiteSpace - remove leading and trailing white spaces
 * @str: original string
 *
 * Return: char *s
 */
char *TrimWhiteSpace(char *str)
{
	char *end;

	/* Trim leading space */
	while (isspace((unsigned char) *str))
		str++;

	if (*str == 0)  /* All spaces? */
		return (str);

	/* Trim trailing space */
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;

	/* Write new null terminator character */
	end[1] = '\0';

	return (str);
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

	token = strtok(str, seperators);

	while (token)
	{
		monty_data.p_data[idx] = token;
		token = strtok(NULL, seperators);
		/* basic check for comment */
		if (idx == 0 && token && token[0] == '#')
		{
			/* add null byte and set in monty data */
			if (token[1])
				token[1] = '\0';
			monty_data.p_data[idx] = token;
			return;
		}
		idx++;
		if (idx == 2)
			return;
	}
	monty_data.p_data[idx] = token;
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
