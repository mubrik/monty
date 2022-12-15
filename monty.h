#ifndef MONTY_H
#define MONTY_H /* MONTY_H */

/* std library */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* definitions */
#define IS_ASCII(n) (n >= 0 && n <= 127)
/* buffer */
typedef char * buf;

/* alx structs */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef void OP_func(stack_t **stack, unsigned int line_number);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	OP_func *f;
} instruction_t;

/* custom structs */

/**
 * struct m_data - Holds the general data for the monty program
 * @file: hol0ds the pointer to the file input
 * @p_action: holds the pointer for each line read from file
 * @d_type: flag for stack or queue. 0 for stack, 1 for queue
 * @stk_head: head node of linked list
 * stk_head
 */
typedef struct m_data
{
	FILE *file;
	int d_type;
	char *p_data[2];
  stack_t *stk_head;
	buf line_buf;
} m_data_t;

extern m_data_t monty_data;

/* ======= stack ops ====== */

/* stack functions */
void Push(stack_t **stk, unsigned int line_number);
void Pop(stack_t **stk, unsigned int line_number);

/* stack-queue functions */
void Swap(stack_t **stk, unsigned int line_number);
void Add(stack_t **stk, unsigned int line_number);
void Pall(stack_t **stk, unsigned int line_number);
void Pint(stack_t **stk, unsigned int line_number);
void Nop(stack_t **stk, unsigned int line_number);
void Sub(stack_t **stk, unsigned int line_number);
void Div(stack_t **stk, unsigned int line_number);
void Mul(stack_t **stk, unsigned int line_number);
void Mod(stack_t **stk, unsigned int line_number);
void Pchar(stack_t **stk, unsigned int line_number);
void Pstr(stack_t **stk, unsigned int line_number);

/* counts of instruction handlers */
#define INS_COUNT 13

/* utility functions */
void update_dtype(char *op);
char *TrimWhiteSpace(char *str);
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number);
void Tokenize(char *str);
void free_m_buff();

/* linked list utility */
stack_t *add_to_node_end(stack_t **head, const int n);
stack_t *add_to_node(stack_t **head, const int n);
stack_t *get_first_node(stack_t **head);
int rm_first_node(stack_t **head);
int rm_last_node(stack_t **head);
size_t print_stk_list(stack_t *head);
void free_stk_list(stack_t **head);
int list_has_2_nodes(stack_t **head);
int list_is_empty(stack_t **head);

#define L_EMPTY(p) list_is_empty(p)
#define L_TW_NODES(p) list_has_2_nodes(p)

#endif /* MONTY_H */
