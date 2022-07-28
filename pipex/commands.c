/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:10:30 by socana-b          #+#    #+#             */
/*   Updated: 2022/07/28 17:02:20 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*verify_commands(char **path, char *cmd)
{
	char	*commnd;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (path[i] && !flag)
	{
		commnd = ft_strjoin(path[i], cmd);
		if (access(commnd, X_OK) == 0)
			flag++;
		else
			free(commnd);
		i++;
	}
	if (!flag)
		commnd = NULL;
	return (commnd);
}

char	**create_path(char **envp)
{
	int		i;
	char	*path;
	char	**all_directions;

	i = 0;
	path = NULL;
	while (envp[i] && !path)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	all_directions = ft_split(path, ':');
	free(path);
	return (all_directions);
}

void	manage_path(char **envp, t_pipy	*my_var)
{
	char	**path;
	char	*bnry1;
	char	*bnry2;
	int		i;

	path = create_path(envp);
	bnry1 = ft_strjoin("/", my_var->command[0][0]);
	bnry2 = ft_strjoin("/", my_var->command[1][0]);
	my_var->path_cmd[0] = verify_commands(path, bnry1);
	my_var->path_cmd[1] = verify_commands(path, bnry2);
	free(bnry1);
	free(bnry2);
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}
