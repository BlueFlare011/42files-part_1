#include "../push_swap.h"

void	push_half(t_stack *a, t_stack *b, t_node *mediana)
{
	int	i;

	i = a->len;
	while (i && ((a->len / 2) != b->len))
	{
		if (a->init->num > mediana->num)
			stack_move(a, b, "ra\n", 2);
		else
			stack_move(a, b, "pb\n", 0);
		i--;
	}
}

void	prototipo_3(t_stack *a, t_stack *b)
{
	t_node	*mediana;

	mediana = mid_node(a);
	push_half(a, b, mediana);
}
