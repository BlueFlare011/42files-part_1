#include "push_swap.h"

void fill_stack(T_Stack *stack, int len, char **args)
{
	
}

void init_stack(T_Stack *stack, int len, char **args, int flag)
{
	stack->num = malloc(sizeof(int) * len - 1);
	max = len - 1;
	if (flag == 0)
		return;
	fill_stack(stack, len, args);
}