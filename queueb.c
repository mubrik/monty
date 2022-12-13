#include "monty.h"

/**
 * q_is_empty - helper func checks if a queue is empty
 * @queue: ptr to the queue struct
 * Return: 1 if full, 0 else
 */
int q_is_empty(queue_t *queue)
{
	if (queue->front == -1)
		return (1);
	return (0);
}

/**
 * q_is_full - checks if a queue is full
 * @queue: ptr to the queue struct
 * @return 1 if full, 0 else
 * Return: 1 if full, 0 else
 */
int q_is_full(queue_t *queue)
{
	if (queue->rear == (QUEUE_SIZE - 1))
		return (1);
	return (0);
}
