/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:50:29 by socana-b          #+#    #+#             */
/*   Updated: 2022/06/24 13:50:33 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(T_Stack *s, int num)
{
	T_Node	*new;

	new = malloc(sizeof(T_Node));
	if (!new)
		return ;
	new->num = num;
	new->next = *s;
	*s = new;
	new->before = NULL;
}

int	is_repeat(T_Stack *s, int num)
{
	T_Node	*aux;
	int		repeat;

	aux = *s;
	repeat = 0;
	while (aux && !repeat)
	{
		if (aux->num == num)
			repeat = 1;
		aux = aux->next;
	}
	return (repeat);
}

void	delete_stack(T_Stack *s)
{
	T_Node	*aux;

	while (*s)
	{
		aux = *s;
		(*s) = (*s)->next;
		if (*s)
			free(aux);
	}
}

void	print_stack(T_Stack *s)
{
	T_Node	*aux;

	aux = *s;
	printf("Del derecho\n");
	while (aux->next)
	{
		printf("%d\n", aux->num);
		aux = aux->next;
	}
	printf("%d\n", aux->num);
	printf("Del reves\n");
	while (aux != (*s))
	{
		printf("%d\n", aux->num);
		aux = aux->before;
	}
	printf("%d\n", aux->num);
}
