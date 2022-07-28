/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:05:55 by socana-b          #+#    #+#             */
/*   Updated: 2022/07/28 13:27:24 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lenght_node(t_stack *a, int less, int *i, int *j)
{
	t_node	*aux;

	aux = *a;
	while (aux->num != less)
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

static t_node	*less_than(t_stack *a)
{
	t_node	*aux;
	t_node	*less;

	aux = *a;
	less = *a;
	while (aux)
	{
		if (aux->num < less->num)
			less = aux;
		aux = aux->next;
	}
	return (less);
}

static t_node	*more_than(t_stack *a)
{
	t_node	*aux;
	t_node	*biggest;

	aux = *a;
	biggest = *a;
	while (aux)
	{
		if (aux->num > biggest->num)
			biggest = aux;
		aux = aux->next;
	}
	return (biggest);
}

static void	algorithm2(t_stack *a, t_stack *b, int i, int j)
{
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

static void	algorithm_for_3(t_stack *a, t_stack *b)
{
	t_node *biggest;

	if (!is_sorted(a))
	{
		biggest = more_than(a);
		if (!biggest->before)
			stack_move(a, b, "ra\n", 2);
		if (biggest->before && biggest->next)
			stack_move(a, b, "rra\n", 3);
		if ((*a)->num > (*a)->next->num)
			stack_move(a, b, "sa\n", 1);
	}
}

void	algorithm(t_stack *a, t_stack *b)
{
	t_node	*less;
	int		i;
	int		j;

	while (stack_lenght(a) > 3 && !is_sorted(a))
	{
		i = 0;
		j = 0;
		less = less_than(a);
		lenght_node(a, less->num, &i, &j);
		algorithm2(a, b, i, j);
		if (!is_sorted(a))
			stack_move(a, b, "pb\n", 0);
	}
	algorithm_for_3(a, b);
	if (*b)
	{
		while (*b)
			stack_move(b, a, "pa\n", 0);
	}
}
