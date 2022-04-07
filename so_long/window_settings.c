#include "so_long.h"

void fillFloor(T_Var *var)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			mlx_put_image_to_window(var->mlx, var->win, var->floor, i * 80, j * 80);
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

void createWindow(T_Var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1200, 1200, "Map");
	var->width = 80;
	var->height = 80;
	var->ness = mlx_xpm_file_to_image(var->mlx, "images/nessSprite.xpm",
	&var->width, &var->height);
	var->floor = mlx_xpm_file_to_image(var->mlx, "images/floorSprite.xpm",
	&var->width, &var->height);
	fillFloor(var);
	mlx_put_image_to_window(var->mlx, var->win, var->ness, 0, 0);
	mlx_key_hook(var->win, key_control, &var);
	mlx_loop(var->mlx);
}
