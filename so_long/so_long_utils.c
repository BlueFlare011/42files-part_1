/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:54:09 by socana-b          #+#    #+#             */
/*   Updated: 2022/04/18 14:54:12 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image_in_window(t_Var *var, int i, int j)
{
	mlx_put_image_to_window(var->mlx, var->win,
		var->floor, j * 80, i * 80);
	if (var->map[i][j] == HOLE)
		mlx_put_image_to_window(var->mlx, var->win,
			var->hole, j * 80, i * 80);
	else if (var->map[i][j] == CHAR)
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->ness, j * 80, i * 80);
		var->ness_x = j * 80;
		var->ness_y = i * 80;
	}
	else if (var->map[i][j] == OBJ)
		mlx_put_image_to_window(var->mlx, var->win,
			var->object, j * 80, i * 80);
	else if (var->map[i][j] == EXIT)
		mlx_put_image_to_window(var->mlx, var->win,
			var->exit, j * 80, i * 80);
}

void	free_map(t_Var *var)
{
	int	i;

	i = 0;
	while (i < var->size_y)
	{
		free(var->map[i]);
		i++;
	}
	free(var->map);
}

void	put_map_in_window(t_Var *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->size_y)
	{
		j = 0;
		while (j < var->size_x)
		{
			put_image_in_window(var, i, j);
			j++;
		}
		i++;
	}
}

void	break_all(t_Var *var)
{
	free_map(var);
	mlx_destroy_image(var->mlx, var->ness);
	mlx_destroy_image(var->mlx, var->object);
	mlx_destroy_image(var->mlx, var->hole);
	mlx_destroy_image(var->mlx, var->floor);
	mlx_destroy_image(var->mlx, var->exit);
	mlx_clear_window(var->mlx, var->win);
}

void	create_images(t_Var *var)
{
	var->width = 80;
	var->height = 80;
	var->ness = mlx_xpm_file_to_image(var->mlx, "images/nessSprite.xpm",
			&var->width, &var->height);
	var->floor = mlx_xpm_file_to_image(var->mlx, "images/floorSprite.xpm",
			&var->width, &var->height);
	var->exit = mlx_xpm_file_to_image(var->mlx, "images/exitSprite.xpm",
			&var->width, &var->height);
	var->hole = mlx_xpm_file_to_image(var->mlx, "images/holeSprite.xpm",
			&var->width, &var->height);
	var->object = mlx_xpm_file_to_image(var->mlx, "images/objectSprite.xpm",
			&var->width, &var->height);
}
