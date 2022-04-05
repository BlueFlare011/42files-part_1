#include "so_long.h"

int	key_control(int keycode, Window *var, Ness *ness)
{
	if (keycode == ESC){
		exit(1);
		mlx_destroy_image(var->mlx, ness->img);
		mlx_clear_window(var->mlx, var->mlx_win);
	}
	if (keycode == KEY_UP)
		ft_move_up(var, ness);
	if (keycode == KEY_DOWN)
		ft_move_down(var, ness);
	if (keycode == KEY_LEFT)
		ft_move_left(var, ness);	
	if (keycode == KEY_RIGHT)
		ft_move_right(var, ness);
	return(0);
}

void createWindow(Window *var, Ness *ness)
{
	var->mlx_win = mlx_new_window(var->mlx, 1000, 1000, "Map");
	ness->width = 0;
	ness->height = 0;
	ness->img = mlx_xpm_file_to_image(var->mlx, "images/nessSprite.xpm", &ness->width, &ness->height);
	ness->ness_x = 0;
	ness->ness_y = 0;
	mlx_put_image_to_window(var->mlx, var->mlx_win, ness->img, ness->ness_x, ness->ness_y);
	mlx_key_hook(var->mlx_win, key_control, &var);
}
