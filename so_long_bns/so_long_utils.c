/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:54:09 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/22 11:19:09 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image_in_window(t_win *win, int i, int j)
{
	mlx_put_image_to_window(win->mlx, win->win,
		win->floor, j * 80, i * 80);
	if (win->map[i][j] == HOLE)
		mlx_put_image_to_window(win->mlx, win->win,
			win->hole, j * 80, i * 80);
	else if (win->map[i][j] == CHAR)
	{
		mlx_put_image_to_window(win->mlx, win->win,
			win->ness, j * 80, i * 80);
		win->ness->ness_x = j * 80;
		win->ness->ness_y = i * 80;
	}
	else if (win->map[i][j] == OBJ)
		mlx_put_image_to_window(win->mlx, win->win,
			win->obj->object, j * 80, i * 80);
	else if (win->map[i][j] == EXIT)
		mlx_put_image_to_window(win->mlx, win->win,
			win->exit, j * 80, i * 80);
}

void	free_map(t_win *win)
{
	int	i;

	i = 0;
	while (i < win->size_y)
	{
		free(win->map[i]);
		i++;
	}
	free(win->map);
}

void	put_map_in_window(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (i < win->size_y)
	{
		j = 0;
		while (j < win->size_x)
		{
			put_image_in_window(win, i, j);
			j++;
		}
		i++;
	}
}

void	break_all(t_win *win)
{
	free_map(win);
	mlx_destroy_image(win->mlx, win->ness);
	mlx_destroy_image(win->mlx, win->object);
	mlx_destroy_image(win->mlx, win->hole);
	mlx_destroy_image(win->mlx, win->floor);
	mlx_destroy_image(win->mlx, win->exit);
	mlx_clear_window(win->mlx, win->win);
}

void	create_images(t_win *win)
{
	win->img_size = 80;
	win->ness = mlx_xpm_file_to_image(win->mlx, "images/nessSprite.xpm",
			&win->img_size, &win->img_size);
	win->floor = mlx_xpm_file_to_image(win->mlx, "images/floorSprite.xpm",
			&win->img_size, &win->img_size);
	win->exit = mlx_xpm_file_to_image(win->mlx, "images/exitSprite.xpm",
			&win->img_size, &win->img_size);
	win->hole = mlx_xpm_file_to_image(win->mlx, "images/holeSprite.xpm",
			&win->img_size, &win->img_size);
	win->object = mlx_xpm_file_to_image(win->mlx, "images/objectSprite.xpm",
			&win->img_size, &win->img_size);
}
