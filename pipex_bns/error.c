/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:10:11 by socana-b          #+#    #+#             */
/*   Updated: 2022/12/14 12:25:47 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(t_pipy *my_var)
{
	free_all_mem(my_var);
	perror("Error: ");
	exit(EXIT_FAILURE);
}

int	are_empty_commands(t_pipy *my_var, int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc - 1)
	{
		if (argv[i++][0] == '\0')
		{
			write(2, "Error: Empty arguments\n", 23);
			free(my_var->path_cmd);
			free(my_var->command);
			return (0);
		}
	}
	return (1);
}

int	manage_error(t_pipy	*my_var, int argc, char **argv, char **envp)
{
	int	i;

	if (!are_empty_commands(my_var, argc, argv))
		return (1);
	i = 1;
	while (i++ < argc - 2)
		my_var->command[i - 2] = ft_split(argv[i], ' ');
	if (manage_path(envp, my_var))
	{
		write (2, "Error: Invalid commands\n", 24);
		free_all_mem(my_var);
		return (2);
	}
	i = 0;
	while (i < my_var->total_commands)
	{
		if (!my_var->path_cmd[i++])
		{
			write (2, "Error: Invalid commands\n", 24);
			free_all_mem(my_var);
			return (2);
		}
	}
	files_management(my_var, argc, argv);
	return (0);
}
