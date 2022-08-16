/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:52:53 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/16 15:45:09 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*aux;
	t_node	*aux2;

	aux = *s;
	aux2 = (*s)->next;
	aux->next = aux2->next;
	aux2->next = aux;
	aux2->before = aux->before;
	aux->before = aux2;
	*s = aux2;
	if (aux->next)
		aux->next->before = aux;
}

void	push(t_stack *s1, t_stack *s2)
{
	t_node	*aux;

	if (*s1)
	{
		aux = (*s1);
		(*s1) = aux->next;
		if (*s1)
			(*s1)->before = NULL;
		aux->next = (*s2);
		(*s2) = aux;
		if (aux->next)
			aux->next->before = aux;
	}
}

void	rotate(t_stack *s)
{
	t_node	*aux;
	t_node	*iter;

	aux = (*s);
	aux->next->before = NULL;
	(*s) = aux->next;
	aux->next = NULL;
	iter = (*s);
	while (iter->next)
		iter = iter->next;
	aux->before = iter;
	iter->next = aux;
}

void	reverse_rotate(t_stack *s)
{
	t_node	*aux;

	aux = (*s);
	while (aux->next)
		aux = aux->next;
	aux->before->next = NULL;
	aux->before = NULL;
	(*s)->before = aux;
	aux->next = (*s);
	(*s) = aux;
}

void	stack_move(t_stack *a, t_stack *b, char *stk, int id_mv)
{
	if (id_mv == 0)
		push(a, b);
	else if (id_mv == 1)
		swap(a);
	else if (id_mv == 2)
		rotate(a);
	else if (id_mv == 3)
		reverse_rotate(a);
	else if (id_mv == 4)
		super_swap(a, b);
	else if (id_mv == 5)
		re_rotate(a, b);
	else if (id_mv == 6)
		re_reverse_rotate(a, b);
	write(1, stk, ft_strlen(stk));
}
