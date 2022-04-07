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

int		error_manager(char **args, int len);
void	printStack(T_Stack *s);
void	fill_stack(T_Stack *s, int* nums, int length);
void	swap(T_Stack *s);
void	push(T_Stack *s1, T_Stack *s2);
void	rotate(T_Stack *s);
void	reverse_rotate(T_Stack *s);

#endif