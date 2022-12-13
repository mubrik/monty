#include "monty.h"

/**
 * Enqueue - Enqueue an id_name_t item
 * @queue: ptr to the queue struct
 * @id: string ptr
 * @name: string ptr
 * @return id_name_t or NULL
 * Return: id_name_t
 */
id_name_t *Enqueue(queue_t *queue, char *id, char *name)
{
	id_name_t *node;
	int rear;

	if (!queue || !id || !name || q_is_full(queue))
		return (NULL);
	/* alloc node */
	node = malloc(sizeof(id_name_t));
	if (!node)
		return (NULL);
	/* node attribs */
	node->id = id, node->name = name;
	/* enqueue */
	rear = queue->rear + 1;
	queue->head[rear] = node;
	if (q_is_empty(queue))
		queue->front = queue->front + 1;
	/* adjust rear */
	queue->rear = rear;
	return (node);
}

/**
 * Dequeue - Dequeue an id_name_t item
 * @queue: ptr to the queue struct
 * @return id_name_t or NULL
 * Return: id_name_t or NULL
 */
id_name_t *Dequeue(queue_t *queue)
{
	id_name_t *node;
	int front;

	if (!queue || q_is_empty(queue))
		return (NULL);
	front = queue->front;
	/* grab front item */
	node = queue->head[front];
	if (!node)
		return (NULL);
	/* push queue fron index */
	++front;
	if (front > queue->rear) /* last item in queue, reset */
		queue->front = -1, queue->rear = -1;
	else
		queue->front = front;
	return (node);
}

/**
 * Q_Peek - Peek an id_name_t item
 * @queue: ptr to the queue struct
 * @return id_name_t or NULL
 * Return: id_name_t or NULL
 */
id_name_t *Q_Peek(queue_t *queue)
{
	id_name_t *node;

	if (!queue || q_is_empty(queue))
		return (NULL);
	/* grab front item */
	node = queue->head[queue->front];
	if (!node)
		return (NULL);
	return (node);
}

/**
 * Q_Free - free's up a malloc'd queue
 * @queue: ptr to the queue struct
 * @return void
 * Return: void
 */
void Q_Free(queue_t *queue)
{
	id_name_t *node;

	while (!q_is_empty(queue))
	{
		node = Dequeue(queue);
		free(node);
	}

	free(queue->head);

}

/**
 * test_queue - test_queue function
 * Return: int
 */
int test_queue(void)
{
	int index, front = 0, rear = 0;
	id_name_t **q_head;
	id_name_t *node;
	queue_t queue;

	/* create head for queue */
	q_head = malloc(sizeof(id_name_t *) * QUEUE_SIZE);
	if (!q_head)
		return (1);
	/* keep queue data in struct for easy organise */
	queue.head = q_head, queue.front = -1, queue.rear = -1;

	/* perform some operation, check mpty */
	printf("Queue is %s \n", q_is_empty(&queue) ? "Empty" : "Not empty");
	/* Enqueue items */
	Enqueue(&queue, "0", "Mubrik"), printf("Adding to Queue\n");
	Enqueue(&queue, "1", "User"), printf("Adding to Queue\n");
	Enqueue(&queue, "2", "Admin"), printf("Adding to Queue\n");
	Enqueue(&queue, "3", "ALX"), printf("Adding to Queue\n");
	/* chcek empty */
	printf("Queue is %s \n", q_is_empty(&queue) ? "Empty" : "Not empty");
	/* len */
	front = queue.front, rear = queue.rear;
	printf("Front queue: %s Rear: %s \n", queue.head[front]->name, queue.head[rear]->name);
	/* check top item */
	node = Q_Peek(&queue);
	if (node)
		printf("Front item in QPeek: %s name: %s \n", node->id, node->name);
	/* Pop a couple and peek, freeing immediately */
	free(Dequeue(&queue)); /* Dequeue Mubrik */
	free(Dequeue(&queue)); /* Dequeue User */
	/* check top item */
	node = Q_Peek(&queue);
	if (node) /* Should be Admin */
		printf("Front item in QPeek: %s name: %s \n", node->id, node->name);
	/* len */
	front = queue.front, rear = queue.rear;
	printf("Front queue: %s Rear: %s\n", queue.head[front]->name, queue.head[rear]->name);
	/* perform some operation, check mpty */
	printf("Queue is %s \n", q_is_full(&queue) ? "Full" : "Not full");
	/* fill it up */
	for (index = 0; index < QUEUE_SIZE; index++)
		Enqueue(&queue, "8", "fill");
	/* check full */
	printf("Queue is %s \n", q_is_full(&queue) ? "Full" : "Not full");
	/* len */
	printf("Rear of queue %d \n", queue.rear);
	/* free queue */
	Q_Free(&queue);
	return (0);
}
