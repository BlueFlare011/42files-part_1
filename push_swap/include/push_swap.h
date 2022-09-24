/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:09:51 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 10:48:39 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int					num;
	unsigned int		id;
	struct s_node		*next;
	struct s_node		*before;
}t_node;

typedef struct s_stack
{
	t_node			*init;
	t_node			*final;
	unsigned int	len;
}t_stack;

// Parcheo
int		error_manager(char **args);
int		args_settings(char **argv, int argc, t_stack *s);
// Funciones para pila
void	print_stack(t_stack *s); //Funcion auxiliar
void	add_stack(t_stack *s, int num);
void	delete_stack(t_stack *s);
int		is_sorted(t_stack *s);
void	set_id(t_stack *a);
//Moviminetos del stack
void	stack_move(t_stack *a, t_stack *b, char *stk, int id_mv);
void	push(t_stack *s1, t_stack *s2);		//id 0
void	swap(t_stack *s);					//id 1
void	rotate(t_stack *s);					//id 2
void	reverse_rotate(t_stack *s);			//id 3
void	super_swap(t_stack *a, t_stack *b);	//id 4
void	re_rotate(t_stack *a, t_stack *b);	//id 5
void	re_reverse_rotate(t_stack *a, t_stack *b); //id 6
//Funciones para algoritmo
void	algorithm(t_stack *a, t_stack *b); //Normal
void	by_chunks(t_stack *a, t_stack *b); //By_chunks!
void	lenght_node(t_node *a, int num, int *i, int *j);
t_node	*less_than(t_stack *a, int limit);
t_node	*greater_than(t_stack *a, int limit);
t_node	*mid_node(t_stack *a);
void	move_num_up(t_stack *s, int to_up);
void	move_num_up_b(t_stack *s, int to_up);
#endif

/*
Apuntar maximo de instrucciones por numero de elemnetos:
- 3 elem = 2 o 3 moves
- 5 elem = 12 moves
- 100 elem = 700 moves
- 500 elem = 5500 moves
*/