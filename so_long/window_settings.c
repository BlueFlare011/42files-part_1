#include "so_long.h"

void fill_map(T_Var *var)
{
	int i;
	int j;

	i = 0;
	j = 0;
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

int	key_control(int keycode, T_Var *var)
{
	if (keycode == ESC){
		exit(1);
		// mlx_destroy_image(var->mlx, ness->img);
		// mlx_clear_window(var->mlx, var->win);
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

void create_window(T_Var *var, T_Valid *valid)
{
	var->mlx = mlx_init();
	var->size_x = valid->size_x;
	var->size_y = valid->size_y;
	var->win = mlx_new_window(var->mlx, var->size_x * 80, var->size_y * 80, "Map");
	create_images(var);
	fill_map(var);
	mlx_put_image_to_window(var->mlx, var->win, var->ness, 0, 0);
	var->ness_x = 0;
	var->ness_y = 0;
	mlx_key_hook(var->win, key_control, var);
	mlx_loop(var->mlx);
}
