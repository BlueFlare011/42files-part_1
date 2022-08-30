/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:52:53 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/30 22:47:51 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*aux;
	t_node	*aux2;

	aux = s->init;
	aux2 = s->init->next;
	aux->next = aux2->next;
	aux2->next = aux;
	aux2->before = aux->before;
	aux->before = aux2;
	s->init = aux2;
	if (aux->next)
		aux->next->before = aux;
}

void	push(t_stack *s1, t_stack *s2)
{
	t_node	*aux;

	if (s1->init)
	{
		aux = s1->init;
		s1->init = aux->next;
		if (s1->init)
			s1->init->before = NULL;
		aux->next = s2->init;
		s2->init = aux;
		if (aux->next)
			aux->next->before = aux;
		s1->len--;
		s2->len++;
	}
}

void	rotate(t_stack *s)
{
	t_node	*aux;
	t_node	*last;

	aux = s->init;
	aux->next->before = NULL;
	s->init = aux->next;
	aux->next = NULL;
	last = s->final;
	aux->before = last;
	last->next = aux;
}

void	reverse_rotate(t_stack *s)
{
	t_node	*aux;

	aux = s->final;
	aux->before->next = NULL;
	aux->before = NULL;
	s->init->before = aux;
	aux->next = s->init;
	s->init = aux;
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
