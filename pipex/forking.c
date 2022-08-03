/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:31 by blueflare         #+#    #+#             */
/*   Updated: 2022/08/03 20:10:02 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_out(t_pipy *my_var, int *fd_pipe)
{
	close(fd_pipe[1]);
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(my_var->outfile, STDOUT_FILENO);
	close(fd_pipe[0]);
	if (execve(my_var->path_cmd[1], my_var->command[1], NULL) == -1)
		write(2, "Error: No se ha podido ejecutar el segundo comando\n", 51);
}

void	child_in(t_pipy *my_var, int *fd_pipe)
{
	close(fd_pipe[0]);
	dup2(my_var->infile, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[1]);
	if (execve(my_var->path_cmd[0], my_var->command[0], NULL) == -1)
		write(2, "Error: No se ha podido ejecutar el primer comando\n", 50);
}

int	forking(t_pipy	*my_var)
{
	int		fd_pipe[2];
	pid_t	process_1;
	pid_t	process_2;

	if (pipe(fd_pipe) == -1)
		return (-1);
	process_1 = fork();
	if (process_1 == -1)
		return (-1);
	if (process_1 == 0)
		child_in(my_var, fd_pipe);
	process_2 = fork();
	if (process_2 == -1)
		return (-1);
	if (process_2 == 0)
		child_out(my_var, fd_pipe);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(process_1, NULL, 0);
	waitpid(process_2, NULL, 0);
	return (1);
}
