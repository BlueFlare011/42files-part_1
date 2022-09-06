#include "../push_swap.h"
/*
void	poll(t_stack *a, t_stack *b, unsigned int limit) // Organizar mejor que hacer
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	aux;
	t_node			*mid;
	t_node			*end;

	i = 0;
	j = 0;
	mid = a->init;
	end = a->final;
	aux = a->len / 2;
	while (aux) //Funcion aparte ?
	{
		mid = mid->next;
		aux--;
	}
	while (end->id > limit)
	{
		i++;
		end = end->before;
	}
	while (mid && mid->id < limit)
		mid = mid->before;
	if (!mid && )
}*/

void	push_by_five(t_stack *a, t_stack *b, unsigned int limit)
{
	unsigned int	i;
	int				j;
	int				len;

	j = 1;
	while (a->init)
	{
		len = a->len;
		if (j <= 5)
		{
			i = limit * j;
			while (len > 0 && b->len != i) //Condicion añadida
			{
				if (a->init->id > i)
					stack_move(a, b, "ra\n", 2);
				else
					stack_move(a, b, "pb\n", 0);
				len--;
			}
		}
		else
			stack_move(a, b, "pb\n", 0);
		j++;
	}
}

void	high_five(t_stack *a, t_stack *b)
{
	unsigned int	limit;

	limit = a->len / 5;
	if (a->len >= 10)
	{
		push_by_five(a, b, limit);
		while (b->init)
		{
			move_num_up_b(b, greater_than(b, 0)->num);
			stack_move(b, a, "pa\n", 0);
		}
	}
	else
		algorithm(a, b);
}
