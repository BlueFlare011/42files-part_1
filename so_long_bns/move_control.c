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

/*
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
			mlx_put_image_to_window(win->mlx, win->win, win->exit->open,
				win->ness->ness_x, win->ness->ness_y);
		win->ness->ness_y += y;
		win->ness->ness_x += x;
		mlx_put_image_to_window(win->mlx, win->win, win->ness->front_1,
			win->ness->ness_x, win->ness->ness_y);
	}
	else
	{
		break_all(win);
		exit(1);
	}
}
*/

void	manage_move(t_win *win, int x, int y)
{
	int	next_x;
	int	next_y;

	next_x = win->ness->ness_x + x;
	next_y = win->ness->ness_y + y;
	if (x > 0 && y == 0)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			win->ness->ness_x, win->ness->ness_y);
		mlx_put_image_to_window(win->mlx, win->win, win->ness->walk_r,
			next_x - 40, next_y);
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			next_x - 40, next_y);
		mlx_put_image_to_window(win->mlx, win->win, win->ness->right,
			next_x, next_y);
	}
	else if (x < 0 && y == 0)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			win->ness->ness_x, win->ness->ness_y);
		mlx_put_image_to_window(win->mlx, win->win, win->ness->walk_l,
			next_x + 40, next_y);
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			next_x + 40, next_y);
		mlx_put_image_to_window(win->mlx, win->win, win->ness->left,
			next_x, next_y);
	}
	else if (x == 0 && y > 0)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			win->ness->ness_x, win->ness->ness_y);
		mlx_put_image_to_window(win->mlx, win->win, win->ness->front_2,
			next_x, next_y  - 40);
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			next_x, next_y - 40);
		mlx_put_image_to_window(win->mlx, win->win, win->ness->front_1,
			next_x, next_y);
	}
	else if (x == 0 && y < 0)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			win->ness->ness_x, win->ness->ness_y);
		mlx_put_image_to_window(win->mlx, win->win, win->ness->back_2,
			next_x, next_y + 40);
		mlx_put_image_to_window(win->mlx, win->win, win->floor,
			next_x, next_y + 40);
		mlx_put_image_to_window(win->mlx, win->win, win->ness->back_1,
			next_x, next_y);
	}
	win->ness->ness_x = next_x;
	win->ness->ness_y = next_y;
	ft_putnbr_fd(++win->ness->steps, 1);
	write(1, "\n", 1);
}

void	ft_move(t_win *win, int x, int y)
{
	int	next_x;
	int	next_y;

	next_x = (win->ness->ness_x + x) / 80;
	next_y = (win->ness->ness_y + y) / 80;
	if (win->map[next_y][next_x] == HOLE)
		return ;
	manage_move(win, x, y);
	if (win->map[next_y][next_x] == OBJ)
	{
		win->obj->num_obj++;
	}
	else if (win->map[next_y][next_x] == EXIT)
	{
		break_all(win);
		exit(0);
	}
}
