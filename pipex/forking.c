/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:31 by blueflare         #+#    #+#             */
/*   Updated: 2022/08/01 12:34:21 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_pipy *my_var, char **argv, int *fd_pipe)
{
	close(fd_pipe[1]);
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(my_var->outfile, STDOUT_FILENO);
	execve(my_var->path_cmd[1], my_var->command[1], NULL);
	close(fd_pipe[0]);
}

void	child(t_pipy *my_var, char **argv, int *fd_pipe)
{
	close(fd_pipe[0]);
	dup2(my_var->infile, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	execve(my_var->path_cmd[0], my_var->command[0], NULL);
	close(fd_pipe[1]);
}

int	forking(char **argv, t_pipy	*my_var)
{
	int		fd_pipe[2];
	pid_t	process;

	if (pipe(fd_pipe) == -1)
		return (-1);
	process = fork();
	if (process == -1)
		return (-1);
	if (process == 0)
		child(my_var, argv, fd_pipe);
	else
		parent(my_var, argv, fd_pipe);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(process, NULL, 0);
	return (1);
}
