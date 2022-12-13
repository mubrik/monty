#ifndef MONTY_H
#define MONTY_H /* MONTY_H */

/* std library */
#include <stdio.h>
#include <stdlib.h>

/* definitions */
#define BUF_S 1024

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
 * @file: holds the pointer to the file input
 */
typedef struct m_data
{
  FILE *file;
} m_data_t;

/* buffer */
typedef char * buf;

/* stack ops */
#define STACK_SIZE 1024

/**
 * id_name_t - basic struct, holds a struct of string id name
 * @id: id
 * @name: name
 */
typedef struct id_name
{
	char *id;
	char *name;
} id_name_t;

/**
 * stk_t - Holds info about a stack
 * @top: top index of stack
 * @head: head ptr of stack
 */
typedef struct stk
{
	int top;
	id_name_t **head;
} stk_t;

int is_empty(int top);
int is_full(int top);
id_name_t *Peek(stk_t *stk);
id_name_t *Push(stk_t *stk, char *id, char *name);
id_name_t *Pop(stk_t *stk);
void Free(stk_t *stk);
int test_stack(void);

/* stack functions and utility */

int SEmpty(stack_t **stk);
int SFull(stack_t **stk);
stack_t *Push(stack_t **stk, unsigned int line_number);
stack_t *Pop(stack_t **stk, unsigned int line_number);
stack_t *SPeek(stack_t **stk, unsigned int line_number);
void SFree(stack_t **stk);

#define QUEUE_SIZE 1024

/**
 * queue_t - Holds info about a queue
 * @front: top index of queue
 * @rear: rear index of queue
 * @head: head ptr of queue
 */
typedef struct queue
{
	int front;
	int rear;
	id_name_t **head;
} queue_t;

int q_is_empty(queue_t *queue);
int q_is_full(queue_t *queue);
id_name_t *Enqueue(queue_t *queue, char *id, char *name);
id_name_t *Dequeue(queue_t *queue);
id_name_t *Q_Peek(queue_t *queue);
void Q_Free(queue_t *queue);
/* queue functions and utility */

stack_t *Enqueue(stack_t **stk, unsigned int line_number);
stack_t *Dequeue(stack_t **stk, unsigned int line_number);
stack_t *QPeek(stack_t **stk, unsigned int line_number);
int QEmpty(stack_t **stk);
int QFull(stack_t **stk);
void QFree(stack_t **stk);
int test_queue(void);

#endif /* MONTY_H */