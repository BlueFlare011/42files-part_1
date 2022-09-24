/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:50:29 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 10:47:42 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_stack(t_stack *s, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	s->len++;
	new->num = num;
	new->id = 0;
	new->next = s->init;
	if (s->init)
		s->init->before = new;
	else
		s->final = new;
	s->init = new;
	new->before = NULL;
}

void	delete_stack(t_stack *s)
{
	t_node	*aux;

	if (s->init)
	{
		while (s->init)
		{
			aux = s->init;
			s->init = s->init->next;
			free(aux);
		}
	}
}

int	is_sorted(t_stack *s)
{
	int		flag;
	t_node	*aux;

	aux = s->init->next;
	flag = 1;
	while (aux && flag)
	{
		if (aux->num < aux->before->num)
			flag = 0;
		aux = aux->next;
	}
	return (flag);
}

int	set_all_id(t_stack *a)
{
	t_node	*aux;
	int		flag;

	aux = a->init;
	flag = 0;
	while (aux && !flag)
	{
		if (aux->id == 0)
			flag = 1;
		aux = aux->next;
	}
	return (flag);
}

void	set_id(t_stack *a)
{
	t_node			*aux;
	t_node			*less;
	int				max_int;
	unsigned int	i;

	i = 1;
	while (set_all_id(a))
	{
		aux = a->init;
		max_int = 2147483647;
		while (aux)
		{
			if ((aux->id == 0) && (aux->num <= max_int))
			{
				max_int = aux->num;
				less = aux;
			}
			aux = aux->next;
		}
		less->id = i;
		i++;
	}
}
