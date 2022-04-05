#include "so_long.h"

void	ft_move_up(Window *var, Ness *ness)
{
	ness->ness_y = ness->ness_y + 60;
	mlx_put_image_to_window(var->mlx, var->mlx_win, ness->img, ness->ness_x, ness->ness_y);
}

void	ft_move_down(Window *var, Ness *ness)
{
	ness->ness_y = ness->ness_y - 60;
	mlx_put_image_to_window(var->mlx, var->mlx_win, ness->img, ness->ness_x, ness->ness_y);
}

void	ft_move_left(Window *var, Ness *ness)
{
	ness->ness_x = ness->ness_x - 60;
	mlx_put_image_to_window(var->mlx, var->mlx_win, ness->img, ness->ness_x, ness->ness_y);
}

void	ft_move_right(Window *var, Ness *ness)
{
	ness->ness_x = ness->ness_x + 60;
	mlx_put_image_to_window(var->mlx, var->mlx_win, ness->img, ness->ness_x, ness->ness_y);
}
