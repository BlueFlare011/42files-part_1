/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:39:08 by blueflare         #+#    #+#             */
/*   Updated: 2022/08/08 10:41:06 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	mirror(t_stack *a, t_stack *b)
{
	t_node	*less;
	int		i;
	int		j;
	int		length;
	
	length = stack_lenght(a)/2;

	while (stack_lenght(a) > length && !is_sorted(a))
	{
		i = 0;
		j = 0;
		less = less_than(a);
		lenght_node(a, less->num, &i, &j);
		algorithm2(a, b, i, j);
		if (!is_sorted(a))
			stack_move(a, b, "pb\n", 0);
	}
}
