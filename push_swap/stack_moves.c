/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:52:53 by socana-b          #+#    #+#             */
/*   Updated: 2022/06/24 13:52:55 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*aux;

	aux = (*s)->next;
	aux->next->before = (*s);
	(*s)->next = aux->next;
	aux->next = (*s);
	aux->before = NULL;
	(*s)->before = aux;
	(*s) = aux;
}

void	push(t_stack *s1, t_stack *s2)
{
	t_node	*aux;

	aux = (*s1);
	(*s1) = aux->next;
	(*s1)->before = NULL;
	aux->next = (*s2);
	(*s2) = aux;
	if (aux->next)
		aux->next->before = aux;
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
