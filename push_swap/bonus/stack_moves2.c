/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:12:05 by socana-b          #+#    #+#             */
/*   Updated: 2022/07/26 16:56:36 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_bonus.h"

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
