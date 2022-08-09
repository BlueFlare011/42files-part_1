/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:09:51 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/09 12:48:16 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "Libft/libft.h"

typedef struct node
{
	int			num;
	struct node	*next;
	struct node	*before;
}t_node;

typedef t_node	*t_stack;

int		error_manager(char **args);
int		args_settings(char **argv, int argc, t_stack *s);
void	print_stack(t_stack *s); //Funcion auxiliar
void	add_stack(t_stack *s, int num);
int		stack_lenght(t_stack *s);
void	delete_stack(t_stack *s);
int		is_sorted(t_stack *s);
void	stack_move(t_stack *a, t_stack *b, char *stk, int id_mv);
void	super_swap(t_stack *a, t_stack *b);
void	re_rotate(t_stack *a, t_stack *b);
void	re_reverse_rotate(t_stack *a, t_stack *b);
void	lenght_node(t_stack *a, int less, int *i, int *j);
t_node	*less_than(t_stack *a);
t_node	*more_than(t_stack *a);
t_node	*mid_node(t_stack *a);
void	algorithm(t_stack *a, t_stack *b); //Normal
void	mirror(t_stack *a, t_stack *b); //Mirror
#endif
/*
Apuntar maximo de instrucciones por numero de elemnetos:
- 3 elem = 2 o 3 moves
- 5 elem = 12 moves
- 100 elem = 700 moves
- 500 elem = 5500 moves
*/