/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:05:55 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 10:44:13 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algorithm_for_3(t_stack *a, t_stack *b)
{
	t_node	*biggest;

	if (!is_sorted(a))
	{
		biggest = greater_than(a, 0);
		if (!biggest->before)
			stack_move(a, b, "ra\n", 2);
		if (biggest->before && biggest->next)
			stack_move(a, b, "rra\n", 3);
		if (a->init->num > a->init->next->num)
			stack_move(a, b, "sa\n", 1);
	}
}

void	algorithm(t_stack *a, t_stack *b)
{
	t_node	*less;

	while (a->len > 3 && !is_sorted(a))
	{
		less = less_than(a, 0);
		move_num_up(a, less->num);
		if (!is_sorted(a))
			stack_move(a, b, "pb\n", 0);
	}
	algorithm_for_3(a, b);
	while (b->init)
		stack_move(b, a, "pa\n", 0);
}
