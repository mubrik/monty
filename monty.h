#ifndef MONTY_H
#define MONTY_H /* MONTY_H */

/* std library */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* definitions */

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
	void (*f)(stack_t **stack, unsigned int line_number);
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
	char *p_action;
	int d_type;
	char *p_data[2];
  stack_t **stk_head;
} m_data_t;

extern m_data_t monty_data;

/* buffer */
typedef char * buf;

/* ======= stack ops ====== */

/* stack functions */
void Push(stack_t **stk, unsigned int line_number);
void Pop(stack_t **stk, unsigned int line_number);

/* queue functions*/
void Enqueue(stack_t **stk, unsigned int line_number);
void Dequeue(stack_t **stk, unsigned int line_number);

/* stack-queue functions */
void Swap(stack_t **stk, unsigned int line_number);
void Peek(stack_t **stk, unsigned int line_number);
void Pall(stack_t **stk, unsigned int line_number);

/* utility functions */
int Empty(stack_t **stk);
void QFree(stack_t **stk);
void update_dtype(char *op);
char *TrimWhiteSpace(char *str);
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number);
char *Tokenize(char *str);

/* linked list utility */
stack_t *add_to_node_end(stack_t **head, const int n);
stack_t *add_to_node(stack_t **head, const int n);
int *rm_first_node(stack_t **head);
int *rm_last_node(stack_t **head);

#endif /* MONTY_H */
