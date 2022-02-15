#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"


typedef struct
{
	int *num;
	size_t max;
}T_Stack;

int error_manager(char **args, int len);
void init_stack(T_Stack *stack, int len, char **args, int flag);

#endif