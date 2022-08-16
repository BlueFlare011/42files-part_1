/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:39:08 by blueflare         #+#    #+#             */
/*   Updated: 2022/08/16 16:34:51 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mirror(t_stack *a, t_stack *b)
{
	t_node	*aux;
	t_node	*mid;

	aux = *a;
	mid = mid_node(a);
	while (aux)
	{
		if (aux->num < mid->num)
		{
			move_num_up(a, b, aux->num);
			stack_move(a, b, "pb\n", 0);
			aux = *a;
		}
		else
			aux = aux->next;
	}
	write(1, "Sub-algoritmo\n", 14);
	move_num_up(a, b, 7);
	move_num_up(b, a, -6);
}
