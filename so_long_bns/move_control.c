/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:01:37 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/22 11:16:26 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_backend(t_win *win, int x, int y)
{
	int	i;
	int	j;

	i = (win->ness->ness_y + y) / 80;
	j = (win->ness->ness_x + x) / 80;
	if (win->map[i][j] == OBJ)
	{
		win->map[i][j] = '0';
		win->obj->num_obj++;
	}
	if ((win->map[i][j] == EXIT) && (win->obj->num_obj == win->exit->exit_bool))
	{
		printf("%d\n", ++win->ness->steps);
		return (2);
	}
	if (win->map[i][j] != HOLE)
	{
		printf("%d\n", ++win->ness->steps);
		return (1);
	}
	return (0);
}

void	ft_move(t_win *win, int x, int y)
{
	if (move_backend(win, x, y) == 1)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			win->ness->ness_x, win->ness->ness_y);
		if (win->map[win->ness->ness_y / 80][win->ness->ness_x / 80] == EXIT)
			mlx_put_image_to_window(win->mlx, win->win, win->exit,
				win->ness->ness_x, win->ness->ness_y);
		win->ness->ness_y += y;
		win->ness->ness_x += x;
		mlx_put_image_to_window(win->mlx, win->win, win->ness,
			win->ness->ness_x, win->ness->ness_y);
	}
	else
	{
		break_all(win);
		exit(1);
	}
}
