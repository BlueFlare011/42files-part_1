/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:07 by blueflare         #+#    #+#             */
/*   Updated: 2022/07/28 15:14:34 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipy	my_var;

	if (manage_error(&my_var, argc, argv))
	{
		my_var.command[0] = ft_split(argv[2], ' ');
		my_var.command[1] = ft_split(argv[3], ' ');
		manage_path(envp, &my_var);
		if (!my_var.path_cmd[0] || !my_var.path_cmd[1])
		{
			write (1, "Error: Comandos invalidos\n", 26);
			close(my_var.infile);
			close(my_var.outfile);
			return (0);
		}
		forking(argv, &my_var);
	}
	else
		write(1, "Error: El numero de argumentos no es valido\n", 44);
	close(my_var.infile);
	close(my_var.outfile);
	return (0);
}
