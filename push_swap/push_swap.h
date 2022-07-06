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
	int			pos;
	struct node	*next;
	struct node	*before;
}t_node;

typedef t_node	*t_stack;

int		error_manager(char **args);
int		args_settings(char **argv, int argc, t_stack *s);
void	print_stack(t_stack *s); //Funcion auxiliar
void	add_stack(t_stack *s, int num, int pos);
int		stack_lenght(t_stack *s);
void	delete_stack(t_stack *s);
int		is_sorted(t_stack *s);
void	three_elements(t_stack *a, t_stack *b);
void	four_elements(t_stack *a, t_stack *b);
void	five_elements(t_stack *a, t_stack *b);
void	swap(t_stack *s, char sn);
void	push(t_stack *s1, t_stack *s2, char sn);
void	rotate(t_stack *s, char sn);
void	reverse_rotate(t_stack *s, char sn);

#endif