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

void	minmax_nodes(int check, t_stack *stack, int *min, int *max)
{
	t_node	*aux;

	aux = *stack;
	while (aux)
	{
		if (check > aux->num)
			*max = *max + 1;
		else
			*min = *min + 1;
		aux = aux->next;
	}
	*min = *min - 1;
}

t_node	*mid_node(t_stack *a)
{
	t_node	*aux;
	int		min;
	int		max;

	aux = *a;
	while (aux)
	{
		min = 0;
		max = 0;
		minmax_nodes(aux->num, a, &min, &max);
		printf("%d - %d\n", min, max);
		if (min - max >= -1 && min - max <= 1)
			return(aux);
		aux = aux->next;
	}
	write(1, "Algo ha ido mal\n", 16);
	return (NULL);
}
