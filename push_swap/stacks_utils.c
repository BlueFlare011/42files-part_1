#include "push_swap.h"

void fill_stack(T_Stack *s, int* nums, int length)
{
	T_Node	*new;
	T_Node	*aux;
	int		i;

	i = 0;
	while (i < length)
	{
		new = (T_Node*)malloc(sizeof(T_Node));
		if (!new)
			return ;
		new->num = nums[i];
		new->next = (*s);
		(*s) = new;
		new->before = NULL;
		if (new->next)
		{
			aux = new->next;
			aux->before = new;
		}
		i++;
	}
}

void printStack(T_Stack *s)
{
	T_Node *aux;
	aux = *s;

	printf("Del derecho\n");
	while (aux->next)
	{
		printf("%d\n", aux->num);
		aux = aux->next;
	}
	printf("%d\n", aux->num);
	printf("Del reves\n");
	while (aux != (*s))
	{
		printf("%d\n", aux->num);
		aux = aux->before;
	}
	printf("%d\n", aux->num);
}
