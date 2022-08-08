#include "../push_swap.h"

void	lenght_node(t_stack *a, int less, int *i, int *j)
{
	t_node	*aux;

	aux = *a;
	while (aux->num != less)
	{
		(*i) = (*i) + 1;
		aux = aux->next;
	}
	while (aux)
	{
		(*j) = (*j) + 1;
		aux = aux->next;
	}
}

t_node	*less_than(t_stack *a)
{
	t_node	*aux;
	t_node	*less;

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

t_node	*more_than(t_stack *a)
{
	t_node	*aux;
	t_node	*biggest;

	aux = *a;
	biggest = *a;
	while (aux)
	{
		if (aux->num > biggest->num)
			biggest = aux;
		aux = aux->next;
	}
	return (biggest);
}