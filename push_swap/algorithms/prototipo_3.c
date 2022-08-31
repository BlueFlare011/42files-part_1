#include "../push_swap.h"

static void	algorithm_for_3_2(t_stack *a, t_stack *b)
{
	t_node	*biggest;

	if (!is_sorted(a))
	{
		biggest = greater_than(a, 0);
		if (!biggest->before)
			stack_move(a, b, "ra\n", 2);
		if (biggest->before && biggest->next)
			stack_move(a, b, "rra\n", 3);
		if (a->init->num > a->init->next->num)
			stack_move(a, b, "sa\n", 1);
	}
}

void	sort_a(t_stack *a, t_stack *b)
{
	t_node	*less;
	int		i;

	i = 0;
	while (a->len > 3 && !is_sorted(a))
	{
		less = less_than(a, 0);
		move_num_up(a, less->num);
		if (!is_sorted(a))
		{
			stack_move(a, b, "pb\n", 0);
			i++;
		}
	}
	algorithm_for_3_2(a, b);
	while (i > 0)
	{
		stack_move(b, a, "pa\n", 0);
		i--;
	}
}

void	push_half(t_stack *a, t_stack *b, t_node *mediana)
{
	int	i;

	i = a->len;
	while (i && (a->len > b->len))
	{
		if (a->init->num > mediana->num)
			stack_move(a, b, "ra\n", 2);
		else
			stack_move(a, b, "pb\n", 0);
		i--;
	}
}

void	push_to_a(t_stack *a, t_stack *b)
{
	t_node	*greater;

	while (b->init)
	{
		greater = greater_than(b, 0);
		move_num_up_b(b, greater->num);
		stack_move(b, a, "pa\n", 0);
	}
}

void	prototipo_3(t_stack *a, t_stack *b)
{
	t_node	*mediana;

	mediana = mid_node(a);
	push_half(a, b, mediana);
	sort_a(a, b);
	push_to_a(a, b);
}
