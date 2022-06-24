#include "push_swap.h"

void multiple_num(char *arg)
{
	//parchear un argumento si tiene varios numeros
	write(1, "Es multiple\n", 12);
}

int is_multiple(char *arg)
{
	int i;
	int	valid;

	i = 0;
	valid = 1;
	while (arg[i] && valid)
	{
		if ((arg[i] == ' ' || arg[i] == '\t') && (arg[i + 1] == ' ' || arg[i + 1] == '\t'))
			valid = 0;
		if (i == 0 && (arg[i] == ' ' || arg[i] == '\t'))
			valid = 0;
		if (i == ft_strlen(arg) - 1 && (arg[i] == ' ' || arg[i] == '\t'))
			valid = 0;
		i++;
	}
	return (valid);
}

void args_settings(char **argv, int argc, T_Stack *s)
{
	unsigned int i;
	int correct;
	
	correct = 1;
	i = argc - 1;
	while (i > 0 && correct)
	{
		if (is_multiple(argv[i]))
			multiple_num(argv[i]);
		else if (error_manager(argv[i], s))
		{
			correct = 0;
			delete_stack(s);
		}
		else
			add_stack(s, ft_atoi(argv[i]));
		i--;
	}
}