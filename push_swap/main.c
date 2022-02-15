#include "push_swap.h"

int main(int argc, char **argv)
{
	T_Stack s1, s2;

	if (error_manager(argv, argc))
		return (NULL);
	init_stack(&s1, argc, argv, 0);
	init_stack(&s2, argc, argv, 1);
	return (0);
}