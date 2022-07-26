/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:13:11 by socana-b          #+#    #+#             */
/*   Updated: 2022/07/26 15:09:05 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_BONUS_H
# define MY_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../Libft/libft.h"

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
void	algorithm(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b, char **moves);

#endif