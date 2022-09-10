/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:04:15 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/10 09:52:41 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lenght_node(t_node *a, int num, int *i, int *j)
{
	t_node	*aux;

	aux = a;
	while (aux->num != num)
	{
		(*i) = (*i) + 1;
		aux = aux->next;
	}
	while (aux)
	{
		(*j) = (*j) + 1;
		aux = aux->next;
	}
}

t_node	*less_than(t_stack *a, int limit)
{
	t_node	*aux;
	t_node	*less;

	aux = a->init;
	while (limit > 0)
	{
		aux = aux->next;
		limit--;
	}
	less = aux;
	while (aux)
	{
		if (aux->num < less->num)
			less = aux;
		aux = aux->next;
	}
	return (less);
}

t_node	*greater_than(t_stack *a, int limit)
{
	t_node	*aux;
	t_node	*biggest;

	aux = a->init;
	while (limit > 0)
	{
		aux = aux->next;
		limit--;
	}
	biggest = aux;
	while (aux)
	{
		if (aux->num > biggest->num)
			biggest = aux;
		aux = aux->next;
	}
	return (biggest);
}

t_node	*mid_node(t_stack *a)
{
	t_node	*max;
	t_node	*aux;

	max = greater_than(a, 0);
	aux = a->init;
	while (aux)
	{
		if (aux->id == max->id / 2)
			break;
		else
			aux = aux->next;
	}
	return (aux);
}

void	move_num_up(t_stack *s, int to_up) 
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	lenght_node(s->init, to_up, &i, &j);
	if (i < j)
	{
		while (i > 0)
		{
			stack_move(s, NULL, "ra\n", 2);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			stack_move(s, NULL, "rra\n", 3);
			j--;
		}
	}
}

void	move_num_up_b(t_stack *s, int to_up)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	lenght_node(s->init, to_up, &i, &j);
	if (i < j)
	{
		while (i > 0)
		{
			stack_move(s, NULL, "rb\n", 2);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			stack_move(s, NULL, "rrb\n", 3);
			j--;
		}
	}
}
