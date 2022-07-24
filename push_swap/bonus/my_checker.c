#include "my_bonus.h"

void	read_moves(void)
{
	char	*aux;
	char	*move_line;
	char	*scan_in;
	
	aux = ft_strdup("");
	
	while (1)
	{
		aux = move_line;
		if (read(0, &scan_in, 1) <= 0) //segfault
			break;
		move_line = ft_strjoin(aux, scan_in);
		free(aux);
	}
	printf("%s", move_line);
}

void	crear_stack(t_stack *a, t_stack *b)
{
	*a = NULL;
	*b = NULL;
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	
	if (argc > 1)
	{
		crear_stack(&a, &b);
		if (args_settings(argv, argc, &a))
		{
			read_moves();
			print_stack(&a);
		}
		delete_stack(&a);
	}
	return (0);
}
