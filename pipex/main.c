#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	char	**commands1;
	char	**commands2;
	char	*add1;
	char	*add2;

	if (argc == 5)
	{
		commands1 = ft_split(argv[2], ' ');
		commands2 = ft_split(argv[3], ' ');
		manage_path(envp, commands1, commands2, &add1, &add2);
		forking(argv, add1, add2, commands1, commands2);
	}
	else
		write(1, "Error: El numero de argumentos no es valido\n", 44);
	return (0);
}
