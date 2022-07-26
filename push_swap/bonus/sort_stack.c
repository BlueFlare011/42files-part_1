#include "my_bonus.h"

void	push_move(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "pa", 2) == 0)
		//push b, a
	else
		//push a, b
}

void	swap_move(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "sa", 2) == 0)
		//swap a
	else if (ft_strncmp(move, "sb", 2) == 0)
		//swap b
	else
		//swap a
		//swap b
}

void	rotate_move(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "ra", 2) == 0)
		//rotate a
	else if (ft_strncmp(move, "rb", 2) == 0)
		//rotate b
	else if (ft_strncmp(move, "rr", 2) == 0)
		//rotate b
		//rotate a
	else if (ft_strncmp(move, "rrb", 2) == 0)
		//reverse_rotate b
	else if (ft_strncmp(move, "rra", 2) == 0)
		//reverse_rotate a
	else 
		//reverse_rotate a
		//reverse_rotate b
}

void	sort_stack(t_stack *a, t_stack *b, char **moves)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (moves[i][0] == 'p')
			push_move(a, b, moves[i]);
		if (moves[i][0] == 's')
			swap_move(a, b, moves[i]);
		else

		i++;
	}
}
