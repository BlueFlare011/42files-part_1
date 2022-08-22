#include "../push_swap.h"
/*
int	is_top(t_stack *s, int i, int greater)
{
	t_node	*aux;

	aux = *s;
	while (i > 0)
	{
		aux = aux->next;
		i--;
	}
	return (aux->num == greater);
}*/

void	move_num_up_swap(t_stack *s, t_node *to_up)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	lenght_node((*s)->next, to_up->num, &i, &j);
	if (i < j)
	{
		while (i > 0)
		{
			stack_move(s, NULL, "sa\n", 1);
			stack_move(s, NULL, "ra\n", 2);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			stack_move(s, NULL, "rra\n", 3);
			stack_move(s, NULL, "sa\n", 1);
			j--;
		}
	}
}

void	shitty_sort(t_stack *s)
{
	t_node	*greater;
	t_node	*aux;
	int		i;

	i = 0;
	while (!is_sorted(s))
	{
		greater = greater_than(s, i);
		move_num_up(s, NULL, greater->num);
		if (i != 0)
			move_num_up_swap(s, aux);
		aux = greater;
		i++;
	}
}