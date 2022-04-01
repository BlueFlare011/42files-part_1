#include "so_long.h"

int	key_control(int keycode, Vdm *var)
{
	var->ness_x = 0;
	var->ness_y = 0;
	if (keycode == ESC)
		mlx_clear_window(var->mlx, var->mlx_win);
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


void createWindow(Vdm *var)
{
	var->mlx_win = mlx_new_window(var->mlx, 1000, 1000, "Map");
	var->width = 0;
	var->height = 0;
	var->img = mlx_xpm_file_to_image(var->mlx, "images/nessSprite.xpm", &var->width, &var->height);
	var->ness_x = 0;
	var->ness_y = 0;
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, var->ness_x, var->ness_y);
	mlx_key_hook(var->mlx_win, key_control, &var);
}
