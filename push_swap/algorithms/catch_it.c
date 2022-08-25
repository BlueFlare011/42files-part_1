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
		if ((*a)->num > (*a)->next->num)
			stack_move(a, b, "sa\n", 1);
	}
}

void	sort_a(t_stack *a, t_stack *b)
{
	t_node	*less;
	int		i;

	i = 0;
	while (stack_lenght(a) > 3 && !is_sorted(a))
	{
		less = less_than(a, 0);
		move_num_up(a, b, less->num);
		if (!is_sorted(a))
			stack_move(a, b, "pb\n", 0);
		i++;
	}
	algorithm_for_3_2(a, b);
	while (i > 0)
	{
		stack_move(b, a, "pa\n", 0);
		i--;
	}
}

t_node	*over_sized(t_stack *a, t_node *aux, int b)
{
	t_node	*less;
	t_node	*greater;

	greater = greater_than(a, 0);
	less = less_than(a, 0);
	if (b > greater->num || b < less->num)
		return (less);
	return (aux);
}

void	catch(t_stack *a, t_stack *b)
{
	int		num_b;
	t_node	*aux;
	t_node	*last;

	while (*b)
	{
		aux = (*a);
		last = *a;
		num_b = (*b)->num;
		while (last)
			last = last->next;
		if (aux->num < num_b)
		{
			while (aux && !(aux->before->num < num_b && aux->num > num_b))
				aux = aux->next;
		}
		write(1, "holi\n", 5);
		over_sized(a, aux, num_b);
		move_num_up(a, NULL, aux->num);
		stack_move(b, a, "pa\n", 0);
	}
}

void	catch_it(t_stack *a, t_stack *b)
{
	unsigned int	length;
	unsigned int	aux;
	int				i;

	length = stack_lenght(a);
	aux = length / 2;
	i = 0;
	while (aux > 0)
	{
		stack_move(a, b, "pb\n", 0);
		aux--;
	}
	sort_a(a, b);
	catch(a, b);
	move_num_up(a, b, less_than(a, 0)->num);
}
