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

	if (argc > 2)
	{
		crear_stack(&a, &b);
		if (args_settings(argv, argc, &a))
		{
			print_stack(&a);
		}
		delete_stack(&a);
	}
	else
		write(1, "Error: No hay argumentos suficientes, GILIPOLLAS\n", 49);
	return (0);
}

//-2147483648
//Existen numeros repetidos ./push_swap 9 4 23 41 ???
// Puede haber 1 argumento con varios numero, el parche del main esta mal