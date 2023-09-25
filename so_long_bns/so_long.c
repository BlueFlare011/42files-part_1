/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:21 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/22 11:09:41 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_struct(t_win *win)
{
	win->ness = malloc(sizeof(t_ness));
	if (!win->ness)
		exit(1);
	win->obj = malloc(sizeof(t_obj));
	if (!win->obj)
		exit(1);
	win->exit = malloc(sizeof(t_exit));
	if (!win->exit)
		exit(1);
}

int	main(int argc, char **argv)
{
	t_win	win;
	t_Valid	valid;

	if (!valid_map(argc, argv, &valid, &win))
	{
		return (0);
	}
	create_struct(&win);
	win.exit->exit_bool = valid.obj;
	create_window(&win);
	return (0);
}
