#include "../push_swap.h"

t_node	*find_next(t_stack *a, unsigned int mediana)
{
	t_node	*next;

	next = a->init;
	while (next->id > mediana)
		next = next->next;
	return (next);
}

void	find_between(t_stack *b, t_node *to_push)
{
	t_node	*min;
	t_node	*max;
	t_node	*aux;
	int		flag;

	flag = 0;
	aux = b->init;
	min = b->init;
	max = b->init;
	while (aux)
	{
		if (aux->num > min->num && aux->num < to_push->num)
		{
			flag = 1;
			min = aux;
		}
		aux = aux->next;
	}
	if (!flag && min->num > to_push->num)
		min = NULL; //Da igual cual sea NULL que el minimo siempre ira a la cima
	flag = 0;
	aux = b->init;
	while (aux)
	{
		if (aux->num < max->num && aux->num > to_push->num)
		{
			flag = 1;
			max = aux;
		}
		aux = aux->next;
	}
	if (!flag && max->num < to_push->num)
		max = NULL;
}

void	order_b(t_stack *a, t_stack *b, t_node *to_push)
{
	
}

void	push_half(t_stack *a, t_stack *b, unsigned int mediana)
{
	t_node	*next;

	while (b->len != mediana)
	{
		next = find_next(a, mediana);
		if (a->init->id > mediana)
			stack_move(a, b, "ra\n", 2); //Cambiar
		else
			stack_move(a, b, "pb\n", 0);
	}
}

void	prototipo_5(t_stack *a, t_stack *b)
{
	unsigned int	mediana;

	mediana = a->len / 2;
	push_half(a, b, mediana);
}
