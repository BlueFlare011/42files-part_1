/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:10:11 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/04 17:11:07 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	manage_error(t_pipy	*my_var, int argc, char **argv)
{
	if (argc != 5)
	{
		write(1, "Error: El numero de argumentos no es valido\n", 44);
		return (0);
	}
	my_var->infile = open(argv[1], O_RDONLY);
	if (access(argv[4], W_OK | R_OK) == 0)
	{
		unlink(argv[4]);
		my_var->outfile = open(argv[4], O_CREAT | O_RDWR, 0666);
	}
	else
		my_var->outfile = -1;
	if ((my_var->infile == -1) || (my_var->outfile == -1))
	{
		write(1, "Error: No se pueden abrir los ficheros\n", 39);
		return (0);
	}
	if ((argv[2][0] == '\0') || (argv[3][0] == '\0'))
	{
		write(1, "Error: Los comandos estan vacíos\n", 34);
		return (0);
	}
	return (1);
}
