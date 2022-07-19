/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:26 by blueflare         #+#    #+#             */
/*   Updated: 2022/07/19 23:42:40 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
#include <string.h> //no apto
#include <stdio.h> //no apto
#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct
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