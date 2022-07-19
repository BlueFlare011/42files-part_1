#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipy	my_var;

	if (argc == 5)
	{
		my_var.infile = open(argv[1], O_RDONLY);
		my_var.outfile = open(argv[4], O_RDWR);
		my_var.command[0] = ft_split(argv[2], ' ');
		my_var.command[1] = ft_split(argv[3], ' ');
		manage_path(envp, &my_var);
		forking(argv, &my_var);
	}
	else
		write(1, "Error: El numero de argumentos no es valido\n", 44);
	close(my_var.infile);
	close(my_var.outfile);
	return (0);
}
