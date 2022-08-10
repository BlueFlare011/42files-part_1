/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:26 by blueflare         #+#    #+#             */
/*   Updated: 2022/08/10 12:00:44 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "Libft/libft.h"

typedef struct pipy
{
	char	**command[2];
	char	*path_cmd[2];
	int		infile;
	int		outfile;
}t_pipy;

void	forking(t_pipy	*my_var, char **envp);
int		manage_path(char **envp, t_pipy	*my_var);
int		manage_error(t_pipy	*my_var, int argc, char **argv, char **envp);
void	error(t_pipy	*my_var);
void	free_all_mem(t_pipy *my_var);
void	files_management(t_pipy *my_var, char **argv);

#endif