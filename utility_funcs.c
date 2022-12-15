#include "monty.h"
#include <ctype.h>

/**
 * get_func - returns the correct function for a opcode
 * @opcode: string representation of the operation
 *
 * Return: stack or queue operation
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{

	int idx = 0;

	instruction_t arr_structs[] = {
		{ "pall", Pall },
		{ "push", Push },
		{ "pop", Pop },
		{ "swap", Swap }, 
	};

	while (idx < 4)
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
 * SEmpty - helper func checks if a stack is empty
 * @stk: stack head
 * @return 1 if empty, 0 else
 * Return: 1 if full, 0 else
 */
int SEmpty(stack_t **stk)
{
	if (!stk || !(*stk))
		return (1);
	return (0);
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

	// Trim leading space
	while(isspace((unsigned char)*str)) str++;

	if(*str == 0)  // All spaces?
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while(end > str && isspace((unsigned char)*end)) end--;

	// Write new null terminator character
	end[1] = '\0';

	return str;
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
	const char *seperators = " \n";

	token = strtok(str, seperators);

	while (token)
	{	
		monty_data.p_data[idx] = token;
		token = strtok(NULL, seperators);
		idx++;
		if (idx == 2) return;
	}
	
	monty_data.p_data[idx] = token;
}
