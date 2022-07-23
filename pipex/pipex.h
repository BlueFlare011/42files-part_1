/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:26 by blueflare         #+#    #+#             */
/*   Updated: 2022/07/23 15:13:13 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

int		forking(char **argv, t_pipy	*my_var);
void	manage_path(char **envp, t_pipy	*my_var);
int		manage_error(t_pipy	*my_var, int argc, char **argv);
#endif