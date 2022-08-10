/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:10:11 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/10 12:05:12 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(t_pipy *my_var)
{
	free_all_mem(my_var);
	perror("Error: ");
	exit(EXIT_FAILURE);
}

int	manage_error(t_pipy	*my_var, int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		write(2, "Error: Bad arguments number\n", 28);
		exit(EXIT_FAILURE);
	}
	if ((argv[2][0] == '\0') || (argv[3][0] == '\0'))
	{
		write(2, "Error: Empty commands\n", 22);
		exit(EXIT_FAILURE);
	}
	my_var->command[0] = ft_split(argv[2], ' ');
	my_var->command[1] = ft_split(argv[3], ' ');
	if (manage_path(envp, my_var)
		|| !my_var->path_cmd[0] || !my_var->path_cmd[1])
	{
		write (2, "Error: Invalid commands\n", 24);
		free_all_mem(my_var);
		exit(EXIT_FAILURE);
	}
	files_management(my_var, argv);
	return (1);
}
