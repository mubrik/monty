#include "monty.h"

void Swap(stack_t **stk, int unsigned line_number)
{

}


void Pall(stack_t **stk, int unsigned line_number)
{
	stack_t *ptr = *stk;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
