/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:10:11 by socana-b          #+#    #+#             */
/*   Updated: 2022/08/09 11:04:55 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	manage_error(t_pipy	*my_var, int argc, char **argv)
{
	if (argc != 5)
	{
		write(2, "Error: Bad arguments number\n", 28);
		return (0);
	}
	if ((argv[2][0] == '\0') || (argv[3][0] == '\0'))
	{
		write(2, "Error: Empty commands\n", 22);
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
		perror("Error: ");
		return (0);
	}
	return (1);
}
