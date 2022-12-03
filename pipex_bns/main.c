/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:07 by blueflare         #+#    #+#             */
/*   Updated: 2022/08/10 14:05:18 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Funcion prototipo
int	create_arrays(t_pipy *my_var, int argc)
{
	if (argc < 5)
	{
		write(2, "Error: Bad arguments number\n", 28);
		return (0);
	}
	my_var->command = malloc(sizeof(char **) * my_var->total_commands);
	if (!my_var->command)
		return (0);
	my_var->path_cmd = malloc(sizeof(char *) * my_var->total_commands);
	if (!my_var->path_cmd)
	{
		free(my_var->command);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipy	my_var;

	my_var.total_commands = argc - 3;
	if (create_arrays(&my_var, argc) && manage_error(&my_var, argc, argv, envp))
	{
		forking(&my_var, envp);
		free_all_mem(&my_var);
		close(my_var.infile);
		close(my_var.outfile);
	}
	return (0);
}
