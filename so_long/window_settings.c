/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:40:48 by socana-b          #+#    #+#             */
/*   Updated: 2022/04/18 14:40:50 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit(1);
	return (0);
}

int	key_control(int keycode, t_Var *var)
{
	if (keycode == ESC)
	{
		break_all(var);
		exit(1);
	}
	if (keycode == KEY_UP)
		ft_move_up(var);
	if (keycode == KEY_DOWN)
		ft_move_down(var);
	if (keycode == KEY_LEFT)
		ft_move_left(var);
	if (keycode == KEY_RIGHT)
		ft_move_right(var);
	return (0);
}

void	create_window(t_Var *var)
{
	var->num_obj = 0;
	var->steps = 0;
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->size_x * 80,
			var->size_y * 80, "Map");
	create_images(var);
	put_map_in_window(var);
	mlx_key_hook(var->win, key_control, var);
	mlx_hook(var->win, 17, 1L << 17, close_window, var);
	mlx_loop(var->mlx);
}
