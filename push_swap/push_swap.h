#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"


typedef struct Node
{
	int num;
	struct Node *next;
	struct Node *before;
}T_Node;

typedef T_Node *T_Stack;

int		error_manager(char *arg, T_Stack *s);
void	print_stack(T_Stack *s);
void	add_stack(T_Stack *s, int num);
int		is_repeat(T_Stack *s, int num);
void	delete_stack(T_Stack *s);
void	swap(T_Stack *s);
void	push(T_Stack *s1, T_Stack *s2);
void	rotate(T_Stack *s);
void	reverse_rotate(T_Stack *s);
void	args_settings(char **argv, int argc, T_Stack *s);

#endif