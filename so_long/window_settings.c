#include "so_long.h"

void fill_floor(T_Var *var)
{
	int i;
	int j;

	i = 0;
	while (i < var->size_y)
	{
		j = 0;
		while (j < var->size_x)
		{
			mlx_put_image_to_window(var->mlx, var->win, var->floor, j * 80, i * 80);
			j++;
		}
		i++;
	}
}

void put_map_in_window(T_Var *var)
{
	int i;
	int j;

	i = 0;
	while (i < var->size_y)
	{
		j = 0;
		while (j < var->size_x)
		{
			if (var->map[i][j] == HOLE)
				mlx_put_image_to_window(var->mlx, var->win, var->hole, j * 80, i * 80);
			else if (var->map[i][j] == CHAR)
			{
				mlx_put_image_to_window(var->mlx, var->win, var->ness, j * 80, i * 80);
				var->ness_x = j * 80;
				var->ness_y = i * 80;
			}
			else if (var->map[i][j] == OBJ)
				mlx_put_image_to_window(var->mlx, var->win, var->object, j * 80, i * 80);
			else if (var->map[i][j] == EXIT)
				mlx_put_image_to_window(var->mlx, var->win, var->exit, j * 80, i * 80);
			j++;
		}
		i++;
	}
}

int	key_control(int keycode, T_Var *var)
{
	if (keycode == ESC){
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
	return(0);
}

void create_window(T_Var *var)
{
	var->num_obj = 0;
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->size_x * 80, var->size_y * 80, "Map");
	create_images(var);
	fill_floor(var);
	put_map_in_window(var);
	mlx_key_hook(var->win, key_control, var);
	mlx_loop(var->mlx);
}
