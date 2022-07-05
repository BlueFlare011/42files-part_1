#include "push_swap.h"

void	check_leaks(void)
{
	system("push_swap leaks");
}

void crear_stack(t_stack *s1, t_stack *s2)
{
	*s1 = NULL;
	*s2 = NULL;
}

int main(int argc, char **argv)
{
	//atexit(check_leaks);
	t_stack s1, s2;

	crear_stack(&s1, &s2);
	if (args_settings(argv, argc, &s1))
	{
		print_stack(&s1);
	}
	delete_stack(&s1);
	return (0);
}
