/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:49:11 by socana-b          #+#    #+#             */
/*   Updated: 2022/12/28 11:04:34 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	files_management(t_pipy *my_var, int argc, char **argv)
{
	if (access(argv[argc - 1], W_OK | R_OK) == 0 && access(argv[1], R_OK) == 0)
	{
		unlink(argv[argc - 1]);
		my_var->outfile = open(argv[argc - 1], O_CREAT | O_RDWR, 0666);
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
	int	j;

	i = 0;
	while (i < my_var->total_commands)
	{
		if (my_var->path_cmd[i])
			free(my_var->path_cmd[i]);
		i++;
	}
	free(my_var->path_cmd);
	i = 0;
	while (i < my_var->total_commands)
	{
		j = 0;
		while (my_var->command[i][j])
		{
			free(my_var->command[i][j]);
			j++;
		}
		free(my_var->command[i]);
		i++;
	}
	free(my_var->command);
}
