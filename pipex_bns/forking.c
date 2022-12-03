/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:31 by blueflare         #+#    #+#             */
/*   Updated: 2022/12/03 10:36:50 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipy *my_var, t_pipe *fd_pipe, char **envp, int index)
{
	int	j;

	j = 0;
	if (index == 0)
	{
		dup2(my_var->infile, STDIN_FILENO);
		dup2(fd_pipe[index][1], STDOUT_FILENO);
	}
	else if (index == (my_var->total_commands - 1))
	{
		dup2(fd_pipe[index - 1][0], STDIN_FILENO);
		dup2(my_var->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(fd_pipe[index - 1][0], STDIN_FILENO);
		dup2(fd_pipe[index][1], STDOUT_FILENO);
	}
	while (j < my_var->total_commands - 1)
	{
		close(fd_pipe[j][0]);
		close(fd_pipe[j++][1]);
	}
	execve(my_var->path_cmd[index], my_var->command[index], envp);
	exit(1);
}

void	forking(t_pipy	*my_var, char **envp)
{
	pid_t	*process;
	t_pipe	*fd_pipe;
	int		i;
	
	i = 0;
	process = malloc(sizeof(pid_t) * my_var->total_commands);
	if (!process)
		error(my_var);
	fd_pipe = malloc(sizeof(t_pipe) * (my_var->total_commands - 1));
	if (!fd_pipe)
	{
		free(process);
		error(my_var);
	}
	while (i < my_var->total_commands - 1)
	{
		if (pipe(fd_pipe[i]) == -1)
			error(my_var);
		i++;
	}
	i = 0;
	while (i < my_var->total_commands)
	{
		process[i] = fork();
		if (process[i] == -1)
			error(my_var);
		if (process[i] == 0)
			child_process(my_var, fd_pipe, envp, i);
		i++;
	}
	i = 0;
	while (i < my_var->total_commands - 1)
	{
		close(fd_pipe[i][0]);
		close(fd_pipe[i][1]);
		i++;
	}
	i = 0;
	while (i < my_var->total_commands)
		waitpid(process[i++], NULL, 0);
	free(process);
	free(fd_pipe);
}
