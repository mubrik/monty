#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"

/* definition of m_data_t global variable */
m_data_t monty_data;

/**
 * main - main function int argc, char *argv[]
 * @argc: argument count
 * @argv: array of char argument values
 * Return: int
 */
int main(int argc, char **argv)
{
	OP_func *p_func = NULL;
	FILE *file = NULL;
	buf line_buf = NULL;
	ssize_t n_read;
	size_t read_l, line_number = 1;
	/* check if argc exactly 2, name and file */
	if (argc != 2)
		err_handler(ERR_ANF, NULL, line_number, 1);
	/* open file and check */
	file = fopen(argv[1], "r");
	if (!file)
		err_handler(ERR_FNF, argv[1], line_number, 1);
	/* store struct */
	monty_data.file = file, monty_data.d_type = 0;
	/* main iteration */
	while ((n_read = getline(&line_buf, &read_l, file)) != -1)
	{
		/* set to allow free later */
		monty_data.line_buf = line_buf;
		Tokenize(line_buf); /* mutates line buf */
		/* get operator func */
		p_func = get_func(monty_data.p_data[0]);
		if (p_func)
			p_func(&monty_data.stk_head, line_number);
		else if (monty_data.p_data[0])
			/* p_data[0] is valid but no instruction handler */
			/* NULL == Blank line */
			err_handler(ERR_INF, monty_data.p_data[0], line_number, 1);
		line_number++;
	}
	free_m_buff();
	return (0);
}
