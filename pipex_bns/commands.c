/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:10:30 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/10 13:59:38 by socana-b         ###   ########.fr       */
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
	all_directions = NULL;
	path = NULL;
	while (envp[i] && !path)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	if (path && path[0] != '\0')
	{
		all_directions = ft_split(path, ':');
		free(path);
	}
	return (all_directions);
}

int	manage_path(char **envp, t_pipy	*my_var)
{
	char	**path;
	char	**bnry;
	int		i;

	bnry = malloc(sizeof(char *) * my_var->total_commands);
	if (!bnry)
		return (1);
	path = create_path(envp);
	if (path)
	{
		i = 0;
		while (i < my_var->total_commands)
		{
			bnry[i] = ft_strjoin("/", my_var->command[i][0]);
			i++;
		}
		i = 0;
		while (i < my_var->total_commands)
		{
			my_var->path_cmd[i] = verify_commands(path, bnry[i]);
			i++;
		}
		i = 0;
		while (path[i])
		{
			free(path[i]);
			i++;
		}
		free(path);
		i = 0;
		while (i < my_var->total_commands)
		{
			free(bnry[i]);
			i++;
		}
		free(bnry);
		return (0);
	}
	return (1);
}
