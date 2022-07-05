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

int	is_repeat(t_stack *s, int num)
{
	t_node	*aux;
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

void	delete_stack(t_stack *s)
{
	t_node	*aux;

	while (*s)
	{
		aux = *s;
		(*s) = (*s)->next;
		if (*s)
			free(aux);
	}
}

void	print_stack(t_stack *s)
{
	t_node	*aux;

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

void addStack(t_stack *s, int num)
{
	t_node *new;
	
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->num = num;
	new->before = NULL;
	new->next = *s;
	*s = new;
}

int isInStack(t_stack *s, int num)
{
	t_node *aux;
	int equal = 0;
	
	aux = *s;
	while(aux && !equal)
	{
		if (aux->num == num)
			equal = 1;
		aux = aux->next;
	}
	return (equal);
}
