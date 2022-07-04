#include "push_swap.h"

static char	**create_matrix(char **argv, int argc)
{
	char	**matrix_args;
	char	*array_args;
	char	*aux;
	int i;

	i = 1;
	array_args = ft_strdup("");
	while (i < argc)
	{
		aux = array_args;
		array_args = ft_strjoin(array_args, argv[i]);
		free(aux);
		aux = array_args;
		array_args = ft_strjoin(array_args, " ");
		free(aux);
		i++;
	}
	matrix_args = ft_split(array_args, ' ');
	free(array_args);
	return (matrix_args);
}

void	delete_matrix(char **args)
{
	int i;

	i = 0;
	while(args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	add_to_stack(char **args, t_stack *s)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	i--;
	while (i >= 0)
	{
		add_stack(s, ft_atoi(args[i]));
		i--;
	}
}

void	args_settings(char **argv, int argc, t_stack *s)
{
	char	**args;

	args = create_matrix(argv, argc);
	

	if (error_manager(args)){
		add_to_stack(args, s);
	}
	else{
		delete_matrix(argv);
	}
}
