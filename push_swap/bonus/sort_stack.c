/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:48:17 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 13:00:14 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/my_bonus.h"

void	push_move(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "pa", 2) == 0)
		push(b, a);
	else
		push(a, b);
}

void	swap_move(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(move, "sb", 2) == 0)
		swap(b);
	else
		super_swap(a, b);
}

void	rotate_move(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "ra", 3) == 0)
		rotate(a);
	else if (ft_strncmp(move, "rb", 3) == 0)
		rotate(b);
	else if (ft_strncmp(move, "rr", 3) == 0)
		re_rotate(a, b);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(move, "rra", 3) == 0)
		reverse_rotate(a);
	else
		re_reverse_rotate(a, b);
}

void	sort_stack(t_stack *a, t_stack *b, char **moves)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (moves[i][0] == 'p')
			push_move(a, b, moves[i]);
		else if (moves[i][0] == 's')
			swap_move(a, b, moves[i]);
		else
			rotate_move(a, b, moves[i]);
		i++;
	}
}
