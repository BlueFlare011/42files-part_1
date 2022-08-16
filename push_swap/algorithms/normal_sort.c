/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:05:55 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/01 12:14:19 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	algorithm_for_3(t_stack *a, t_stack *b)
{
	t_node	*biggest;

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

	while (stack_lenght(a) > 3 && !is_sorted(a))
	{
		less = less_than(a);
		move_num_up(a, b, less->num);
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
