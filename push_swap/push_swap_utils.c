#include "push_swap.h"

static void	lenght_node(t_stack *a, int less, int *i, int *j)
{
	t_node *aux = *a;
	
	while (aux->num != less)
	{
		(*i) = (*i) + 1;
		aux = aux->next;
	}
	while(aux)
	{
		(*j) = (*j) + 1;
		aux = aux->next;
	}
}

static t_node	*less_than(t_stack *a)
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

void	algorithm(t_stack *a, t_stack *b)
{
	t_node	*less;
	int		i;
	int		j;
	
	while (stack_lenght(a) > 2)
	{
		i = 0;
		j = 0;
		less = less_than(a);
		lenght_node(a, less->num, &i, &j);
		if (i < j)
		{
			while (i > 0)
			{
				stack_move(a, b, "ra\n", 2);
				i--;
			}
		}
		else
		{
			while (j > 0)
			{
				stack_move(a, b, "rra\n", 3);
				j--;
			}
		}
		stack_move(a, b, "pa\n", 0);
	}
	if ((*a)->num > (*a)->next->num)
		stack_move(a, b, "sa\n", 1);
	if (*b)
	{
		while (*b)
			stack_move(b, a, "pb\n", 0);
	}
}
