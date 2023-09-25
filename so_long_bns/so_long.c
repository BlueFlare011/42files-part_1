/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:21 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/25 15:18:03 by blueflare01      ###   ########.fr       */
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
	win.exit->exit_goal = valid.obj;
	create_window(&win);
	return (0);
}
