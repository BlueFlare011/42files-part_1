/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:40:48 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/22 11:13:07 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit(1);
	return (0);
}

int	key_control(int keycode, t_win *win)
{
	if (keycode == ESC)
	{
		break_all(win);
		exit(1);
	}
	if (keycode == KEY_UP)
		ft_move(win, 0, -80);
	if (keycode == KEY_DOWN)
		ft_move(win, 0, 80);
	if (keycode == KEY_LEFT)
		ft_move(win, -80, 0);
	if (keycode == KEY_RIGHT)
		ft_move(win, 80, 0);
	return (0);
}

void	create_window(t_win *win)
{
	win->obj->num_obj = 0;
	win->ness->steps = 0;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->size_x * 80,
			win->size_y * 80, "Map");
	create_images(win);
	put_map_in_window(win);
	mlx_key_hook(win->win, key_control, win);
	mlx_hook(win->win, 17, 1L << 17, close_window, win);
	mlx_loop(win->mlx);
}
