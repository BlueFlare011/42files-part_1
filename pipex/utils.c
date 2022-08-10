/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:49:11 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/10 12:26:27 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	files_management(t_pipy *my_var, char **argv)
{
	if (access(argv[4], W_OK | R_OK) == 0 && access(argv[1], R_OK) == 0)
	{
		unlink(argv[4]);
		my_var->outfile = open(argv[4], O_CREAT | O_RDWR, 0666);
		my_var->infile = open(argv[1], O_RDONLY);
	}
	else
		error(my_var);
	if ((my_var->infile == -1) || (my_var->outfile == -1))
		error(my_var);
}

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
