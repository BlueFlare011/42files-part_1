/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:12:05 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 13:00:23 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/my_bonus.h"

void	super_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	re_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	re_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
