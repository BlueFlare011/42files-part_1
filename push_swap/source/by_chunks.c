/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:43:54 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 10:44:42 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	how_many_chunks(t_stack *a)
{
	unsigned int	len;

	len = a->len;
	return ((len + 185) / 57);
}

void	push_by_five(t_stack *a, t_stack *b, unsigned int limit, int chunks)
{
	unsigned int	i;
	int				j;
	int				len;

	j = 1;
	while (a->init)
	{
		len = a->len;
		if (j < chunks)
		{
			i = limit * j;
			while (len > 0 && b->len != i)
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

void	by_chunks(t_stack *a, t_stack *b)
{
	unsigned int	limit;
	int				num_chunks;

	num_chunks = how_many_chunks(a);
	limit = a->len / num_chunks;
	if (a->len >= 10)
	{
		push_by_five(a, b, limit, num_chunks);
		while (b->init)
		{
			move_num_up_b(b, greater_than(b, 0)->num);
			stack_move(b, a, "pa\n", 0);
		}
	}
	else
		algorithm(a, b);
}
