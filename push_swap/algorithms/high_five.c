#include "../push_swap.h"

void	push_by_five(t_stack *a, t_stack *b, int limit)
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
			while (len > 0)
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
	int	limit;

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
