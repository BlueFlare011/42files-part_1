/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:50:29 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/25 21:38:16 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(t_stack *s, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->num = num;
	new->id = 0;
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

void	delete_stack(t_stack *s)
{
	t_node	*aux;

	if (*s)
	{
		while (*s)
		{
			aux = *s;
			(*s) = (*s)->next;
			free(aux);
		}
	}
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
			printf("%d - %u\n", aux->num, aux->id);
			aux = aux->next;
		}
		printf("%d - %u\n", aux->num, aux->id);
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

int	set_all_id(t_stack *a)
{
	t_node	*aux;
	int		flag;

	aux = *a;
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
		aux = *a;
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
