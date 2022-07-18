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

	if (argc > 1)
	{
		crear_stack(&a, &b);
		if (args_settings(argv, argc, &a))
		{
			algorithm(&a, &b);
			printf("Pila ordenada:\n");
			print_stack(&a);
			write(1, "_________________________________________\n", 42);
			print_stack(&b);
		}
		delete_stack(&a);
	}
	return (0);
}

//-2147483648
//Existen numeros repetidos ./push_swap 9 4 23 41 ???
