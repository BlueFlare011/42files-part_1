#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"


typedef struct node
{
	int num;
	struct node *next;
	struct node *before;
}t_node;

typedef t_node *t_stack;

int		error_manager(char **args);
void	print_stack(t_stack *s); //Funcion auxiliar
void	add_stack(t_stack *s, int num);
int		is_repeat(t_stack *s, int num);
void	delete_stack(t_stack *s);
void	swap(t_stack *s);
void	push(t_stack *s1, t_stack *s2);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);
void	args_settings(char **argv, int argc, t_stack *s);

#endif