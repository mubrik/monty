#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - main function int argc, char *argv[]
 * @argc: argument count
 * @argv: array of char argument values
 * Return: int
 */

/* definition of m_data_t global variable */
m_data_t monty_data;

int main(int argc, char **argv)
{
	void (*p_func)(stack_t **stk, unsigned int line_number);
	FILE *file = NULL;
	char *line_buf = NULL;
	ssize_t n_read;
	size_t read_l, line_number = 1;
  stack_t stack_head;

	/* check if argc exactly 2, name and file */
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	/* open file and check */
	file = fopen(argv[1], "r");
	if (!file)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

	/* store struct */
	monty_data.file = file, monty_data.stk_head = &stack_head;

	while ((n_read = getline(&line_buf, &read_l, file)) != -1)
	{
		/* remove leading and trailing white spaces */
		line_buf = TrimWhiteSpace(line_buf);
		/* update the ......... */
		monty_data.p_action = line_buf;
		update_dtype(line_buf);
    monty_data.p_data = Tokenize(line_buf);

		p_func = get_func(monty_data->p_action);
		if (p_func)
			p_func(monty_data.stk_head, line_number);

		line_number++;
	}
	return (0);
}
