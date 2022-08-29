#include "../push_swap.h"

t_node	*near_node(t_stack *a, t_node *mediana)
{
	t_node	*aux_1;
	t_node	*aux_2;
	int		i;
	int		j;

	aux_1 = *a;
	aux_2 = *a;
	i = 0;
	j = 0;
	while (aux_2->next)
		aux_2 = aux_2->next;
	while (aux_1 && aux_1->num > mediana->num)
	{
		i++;
		aux_1 = aux_1->next;
	}
	while (aux_2 && aux_2->num > mediana->num)
	{
		j++;
		aux_2 = aux_2->before;
	}
	if (i <= j)
		return (aux_1);
	else
		return (aux_2);
}

void	push_half(t_stack *a, t_stack *b, t_node *mediana)
{
	t_node	*aux;
	(void)*b;

	while (1)
	{
		aux = near_node(a, mediana);
		if (aux)
		{
			move_num_up(a, b, aux->num);
			stack_move(a, b, "pb\n", 0);
		}
		else
			break ;
	}
}

void	rubens_push_half(t_stack *a, t_stack *b, t_node *mediana)
{
	int	len;
	(void)*b;

	len = stack_lenght(a);
	while (len)
	{
		if ((*a)->num > mediana->num)
			stack_move(a, b, "ra\n", 2);
		else
			stack_move(a, b, "pb\n", 0);
		len--;
	}
}

void	prototipo_3(t_stack *a, t_stack *b)
{
	t_node	*mediana;

	mediana = mid_node(a);
	rubens_push_half(a, b, mediana);
}
