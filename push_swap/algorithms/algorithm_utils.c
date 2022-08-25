/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:04:15 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/25 20:50:09 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lenght_node(t_node *a, int num, int *i, int *j) //Esto hay que cambiar en todo
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

	aux = *a;
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

	aux = *a;
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

void	minmax_nodes(int check, t_stack *stack, int *min, int *max)
{
	t_node	*aux;

	aux = *stack;
	while (aux)
	{
		if (check > aux->num)
			*max = *max + 1;
		else
			*min = *min + 1;
		aux = aux->next;
	}
	*min = *min - 1;
}

t_node	*mid_node(t_stack *a)
{
	t_node	*aux;
	int		min;
	int		max;

	aux = *a;
	while (aux)
	{
		min = 0;
		max = 0;
		minmax_nodes(aux->num, a, &min, &max);
		if (min - max >= -1 && min - max <= 1)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

void	move_num_up(t_stack *a, t_stack *b, int to_up)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	lenght_node(*a, to_up, &i, &j);
	//printf("=%d= %d - %d\n", to_up, i, j);
	if (i < j)
	{
		while (i > 0)
		{
			stack_move(a, b, "ra\n", 2);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			stack_move(a, b, "rra\n", 3);
			j--;
		}
	}
}
