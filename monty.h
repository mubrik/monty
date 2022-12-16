#ifndef MONTY_H
#define MONTY_H /* MONTY_H */

/* std library */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* definitions */
#define IS_ASCII(n) (n >= 0 && n <= 127)
/* buffer */
typedef char *buf;

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

/* IMPORTANT typedef for the functions that handle operations/opcodes */
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
 * @line_buf: holds the pointer for each line read from file
 * @d_type: flag for stack or queue. 0 for stack, 1 for queue
 * @stk_head: head node of linked list
 * @p_data: user inputs
 */
typedef struct m_data
{
	FILE *file;
	int d_type;
	char *p_data[2];
	stack_t *stk_head;
	buf line_buf;
} m_data_t;

/* global data */
extern m_data_t monty_data;

/* ======= stack ops ====== */

/* stack functions */
OP_func Push;
OP_func Pop;

/* stack-queue functions */
OP_func Swap;
OP_func Add;
OP_func Pall;
OP_func Pint;
OP_func Nop;
OP_func Sub;
OP_func Div;
OP_func Mul;
OP_func Mod;
OP_func Pchar;
OP_func Pstr;
OP_func Rotl;
OP_func Rotr;
OP_func Type;

/* counts of instruction handlers */
#define INS_COUNT 17

/* utility functions */
int update_dtype(char *op);
OP_func (*get_func(char *opcode));
void Tokenize(char *str);
void free_m_buff(void);

/* linked list utility */
size_t print_stk_list(stack_t *head);
stack_t *add_to_node_end(stack_t **head, const int n);
stack_t *add_to_node(stack_t **head, const int n);
stack_t *get_first_node(stack_t **head);
stack_t *get_last_node(stack_t **head);
void free_stk_list(stack_t **head);
int rm_first_node(stack_t **head);
int rm_last_node(stack_t **head);
int list_has_2_nodes(stack_t **head);
int list_is_empty(stack_t **head);

/* macros, prefer macros over utilty as utility can change */
#define L_FIRST(p) get_first_node(p)
#define L_LAST(p) get_last_node(p)
#define L_EMPTY(p) list_is_empty(p)
#define L_TW_NODES(p) list_has_2_nodes(p)

/* error enums */
/**
 * enum error_flags - error flag
 * @ERR_ANF: Bad argument / Argument not found
 * @ERR_FNF: Bad file / Fil not found / Cant open
 * @ERR_INF: No instruction / Instruction not found
 * @ERR_SIE: Stack is empty
 * @ERR_SIS: Stack is short error
 * @ERR_PBA: Push instruction bad int
 * @ERR_PPS: POP empty stack
 * @ERR_MME: malloc memory error
 */
enum error_type {
	ERR_ANF = 1 << 0,
	ERR_FNF = 1 << 1,
	ERR_INF = 1 << 2,
	ERR_SIE = 1 << 3,
	ERR_SIS = 1 << 4,
	ERR_PBA = 1 << 5,
	ERR_PPS = 1 << 6,
	ERR_MME = 1 << 7
};

void err_handler(enum error_type err, char *str,
	unsigned int line_num, int ex_code);

#endif /* MONTY_H */
