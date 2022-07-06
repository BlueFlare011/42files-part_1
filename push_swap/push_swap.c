#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks push_swap");
}

void crear_stack(t_stack *a, t_stack *b)
{
	*a = NULL;
	*b = NULL;
}

int main(int argc, char **argv)
{
	//atexit(check_leaks);
	t_stack a, b;

	if (argc != 1)
	{
		crear_stack(&a, &b);
		if (args_settings(argv, argc, &a))
		{
			if (stack_lenght(&a) == 2)
				swap(&a, 'a');
			else if (stack_lenght(&a) == 3)
				three_elements(&a, &b);
			else if (stack_lenght(&a) == 4)
				four_elements(&a, &b);
			else if (stack_lenght(&a) == 5)
				four_elements(&a, &b);
			print_stack(&a);
		}
		delete_stack(&a);
	}
	else
		write(1, "Error: No hay argumentos, GILIPOLLAS\n", 37);
	return (0);
}

//-2147483648