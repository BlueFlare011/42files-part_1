/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:07 by blueflare         #+#    #+#             */
/*   Updated: 2022/08/04 17:20:39 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all_mem(t_pipy *my_var)
{
	int	i;

	i = 0;
	if (my_var->path_cmd[0] || my_var->path_cmd[1])
	{
		free(my_var->path_cmd[0]);
		free(my_var->path_cmd[1]);
	}	
	while (my_var->command[0][i])
	{
		free(my_var->command[0][i]);
		i++;
	}
	i = 0;
	while (my_var->command[1][i])
	{
		free(my_var->command[1][i]);
		i++;
	}
	free(my_var->command[0]);
	free(my_var->command[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipy	my_var;

	if (manage_error(&my_var, argc, argv))
	{
		my_var.command[0] = ft_split(argv[2], ' ');
		my_var.command[1] = ft_split(argv[3], ' ');
		if (manage_path(envp, &my_var)
			|| !my_var.path_cmd[0] || !my_var.path_cmd[1])
		{
			write (1, "Error: Comandos invalidos\n", 26);
			free_all_mem(&my_var);
			close(my_var.infile);
			close(my_var.outfile);
			return (0);
		}
		if (forking(&my_var) == -1)
			write (1, "Error: El Pipe no ha funcionado\n", 32);
		free_all_mem(&my_var);
	}
	close(my_var.infile);
	close(my_var.outfile);
	return (0);
}
