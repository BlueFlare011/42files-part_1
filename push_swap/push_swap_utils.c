#include "push_swap.h"

t_node *less_than(t_stack *a)
{
	t_node *aux;
	t_node *less;
	
	aux = *a;
	less = *a;
	while (aux)
	{
		if (aux->num < less->num)
			less = aux;
		aux = aux->next;
	}
	return (less);
}

void algorithm(t_stack *a, t_stack *b)
{
	
}