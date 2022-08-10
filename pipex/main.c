/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:37:07 by blueflare         #+#    #+#             */
/*   Updated: 2022/08/10 14:05:18 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipy	my_var;

	if (manage_error(&my_var, argc, argv, envp))
	{
		forking(&my_var, envp);
		free_all_mem(&my_var);
	}
	close(my_var.infile);
	close(my_var.outfile);
	return (0);
}
