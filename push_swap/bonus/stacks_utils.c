/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:50:29 by socana-b          #+#    #+#             */
/*   Updated: 2022/07/28 14:01:07 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_bonus.h"

void	add_stack(t_stack *s, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->num = num;
	new->next = *s;
	if (*s != NULL)
		(*s)->before = new;
	*s = new;
	new->before = NULL;
}

int	stack_lenght(t_stack *s)
{
	t_node	*aux;
	int		i;

	aux = *s;
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

void	delete_all(t_stack *s, char **moves)
{
	t_node	*aux;
	int		i;

	i = 0;
	while (*s)
	{
		aux = *s;
		(*s) = (*s)->next;
		free(aux);
	}/*
	while (moves[i])
	{
		free(moves[i]);
		i++;
	}
	free(moves);*/
}

void	print_stack(t_stack *s)
{
	t_node	*aux;

	if (*s)
	{
		aux = *s;
		printf("Del derecho\n");
		while (aux->next)
		{
			printf("%d\n", aux->num);
			aux = aux->next;
		}
		printf("%d\n", aux->num);
	}
	else
		write(1, "Pila vacia\n", 11);
}

int	is_sorted(t_stack *s)
{
	int		flag;
	t_node	*aux;

	aux = (*s)->next;
	flag = 1;
	while (aux && flag)
	{
		if (aux->num < aux->before->num)
			flag = 0;
		aux = aux->next;
	}
	return (flag);
}
