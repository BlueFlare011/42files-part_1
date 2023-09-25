/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare011 <blueflare011@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:54:09 by socana-b          #+#    #+#             */
/*   Updated: 2023/09/25 15:47:54 by blueflare01      ###   ########.fr       */
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
			win->ness->front_1, j * 80, i * 80);
		win->ness->ness_x = j * 80;
		win->ness->ness_y = i * 80;
	}
	else if (win->map[i][j] == OBJ)
		mlx_put_image_to_window(win->mlx, win->win,
			win->obj->object, j * 80, i * 80);
	else if (win->map[i][j] == EXIT)
		mlx_put_image_to_window(win->mlx, win->win,
			win->exit->open, j * 80, i * 80);
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
	mlx_string_put(win->mlx, win->win, 30, 40, 0xFFFFFF, "0");
}

void	break_all(t_win *win)
{
	free_map(win);
	mlx_destroy_image(win->mlx, win->ness->front_1);
	mlx_destroy_image(win->mlx, win->ness->front_2);
	mlx_destroy_image(win->mlx, win->ness->back_1);
	mlx_destroy_image(win->mlx, win->ness->back_2);
	mlx_destroy_image(win->mlx, win->ness->left);
	mlx_destroy_image(win->mlx, win->ness->right);
	mlx_destroy_image(win->mlx, win->ness->walk_l);
	mlx_destroy_image(win->mlx, win->ness->walk_r);
	//mlx_destroy_image(win->mlx, win->obj->obj_open);
	mlx_destroy_image(win->mlx, win->obj->object);
	mlx_destroy_image(win->mlx, win->hole);
	mlx_destroy_image(win->mlx, win->floor);
	mlx_destroy_image(win->mlx, win->exit->open);
	mlx_clear_window(win->mlx, win->win);
}

void	create_images(t_win *win)
{
	win->img_size = 80;
	win->ness->back_1 = mlx_xpm_file_to_image(win->mlx,
		"images/ness_sprites_back1.xpm", &win->img_size, &win->img_size);
	win->ness->back_2 = mlx_xpm_file_to_image(win->mlx,
		"images/ness_sprites_back2.xpm", &win->img_size, &win->img_size);
	win->ness->front_1 = mlx_xpm_file_to_image(win->mlx,
		"images/ness_sprites_front1.xpm", &win->img_size, &win->img_size);
	win->ness->front_2 = mlx_xpm_file_to_image(win->mlx,
		"images/ness_sprites_front2.xpm", &win->img_size, &win->img_size);
	win->ness->left = mlx_xpm_file_to_image(win->mlx,
		"images/ness_sprites_left.xpm", &win->img_size, &win->img_size);
	win->ness->right = mlx_xpm_file_to_image(win->mlx,
		"images/ness_sprites_right.xpm", &win->img_size, &win->img_size);
	win->ness->walk_l = mlx_xpm_file_to_image(win->mlx,
		"images/ness_sprites_left_w.xpm", &win->img_size, &win->img_size);
	win->ness->walk_r = mlx_xpm_file_to_image(win->mlx,
		"images/ness_sprites_right_w.xpm", &win->img_size, &win->img_size);
	win->floor = mlx_xpm_file_to_image(win->mlx,
		"images/floorSprite.xpm", &win->img_size, &win->img_size);
	win->exit->open = mlx_xpm_file_to_image(win->mlx,
		"images/exitSprite.xpm", &win->img_size, &win->img_size);
	win->hole = mlx_xpm_file_to_image(win->mlx,
		"images/holeSprite.xpm", &win->img_size, &win->img_size);
	win->obj->object = mlx_xpm_file_to_image(win->mlx,
		"images/objectSprite.xpm", &win->img_size, &win->img_size);
}
