#include "../push_swap.h"

t_node	*find_next(t_stack *a, unsigned int mediana)
{
	t_node	*next;

	next = a->init;
	while (next && next->id > mediana)
		next = next->next;
	return (next);
}


void	algorithm_for_3_b(t_stack *a, t_stack *b)
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

void	algorithm_b(t_stack *a, t_stack *b)
{
	t_node	*less;

	while (a->len > 3 && !is_sorted(a))
	{
		less = less_than(a, 0);
		move_num_up(a, less->num);
		if (!is_sorted(a))
			stack_move(a, b, "pb\n", 0);
	}
	algorithm_for_3_b(a, b);
	while (b->init)
			stack_move(b, a, "pa\n", 0);
}

void	find_between(t_stack *b, t_node *to_push, t_node **min, t_node **max)
{
	t_node	*aux;
	int		min_int;
	int		max_int;

	aux = b->init;
	*min = NULL;
	*max = NULL;
	min_int = INT_MIN;
	max_int = INT_MAX;
	while (aux)
	{
		if (aux->num < to_push->num && aux->num >= min_int)
		{
			*min = aux;
			min_int = aux->num;
		}
		aux = aux->next;
	}
	aux = b->init;
	while (aux)
	{
		if (aux->num > to_push->num && aux->num <= max_int)
		{
			*max = aux;
			max_int = aux->num;
		}
		aux = aux->next;
	}
}

void	order_b(t_stack *b, t_node *to_push)
{
	t_node	*max;
	t_node	*min;
	t_node	*to_up;

	if (b->len > 1)
	{
		find_between(b, to_push, &min, &max);
		if (!min || !max)
			to_up = greater_than(b, 0);
		else
			to_up = min;
		move_num_up_b(b, to_up->num);
	}
}

int	fit_in(t_stack *b, t_node *next)
{
	t_node	*max;
	t_node	*min;
	int		i;
	int		j;

	i = 0;
	j = 0;
	find_between(b, next, &min, &max);
	if (!min || !max)
		min = greater_than(b, 0);
	lenght_node(b->init, min->num, &i, &j);
	if (i >= j || i == 0)
		return (0);
	else
		return (1);
}

void	push_half(t_stack *a, t_stack *b, unsigned int mediana)
{
	t_node	*next;

	next = find_next(a, mediana);
	while (b->len != mediana)
	{
		if (a->init->id > mediana)
			if (b->len > 1 && fit_in(b, next))
				stack_move(a, b, "rr\n", 5);
			else
				stack_move(a, b, "ra\n", 2);
		else
		{
			order_b(b, a->init);
			stack_move(a, b, "pb\n", 0);
			next = find_next(a, mediana);
		}
	}
	move_num_up_b(b, greater_than(b, 0)->num);
}

void	prototipo_5(t_stack *a, t_stack *b)
{
	unsigned int	mediana;

	mediana = a->len / 2;
	push_half(a, b, mediana);
	algorithm_b(a, b);
}

/*
-8 3 6 -10 -3 10 -4 -1 1 0
10 -9 -10 0 8 7 -6 6 -7 -5
-8 -7 0 -10 10 2 3 4 1 6
0 -4 -6 9 7 -10 2 1 -1 -8
-7 -6 2 -4 1 0 9 4 8 -3
*/