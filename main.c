#include "monty.h"

/**
 * main - main function int argc, char *argv[]
 * @argc: argument count
 * @argv: array of char argument values
 * Return: int
 */
int main(int argc, char **argv)
{
  __attribute__((unused)) m_data_t monty_data;
  FILE *file = NULL;
  buf line_buf = NULL;
  ssize_t n_read;
  size_t read_l;

  /* check if argc exactly 2, name and file */
  if (argc != 2)
    fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
  /* open file and check */
  file = fopen(argv[1], "r");
  if (!file)
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
  /* store struct */
  monty_data.file = file;
  while ((n_read = getline(&line_buf, &read_l, file)) != -1)
    printf("Buffer: %s", line_buf);
  return (0);
}
