#include "push_swap.h"

void crear_stack(t_stack *s1, t_stack *s2)
{
	*s1 = NULL;
	*s2 = NULL;
}

int main(int argc, char **argv)
{
	t_stack s1, s2;

	crear_stack(&s1, &s2);
	args_settings(argv, argc, &s1);
	print_stack(&s1);
	return (0);
}
