#include "so_long.h"

void	ft_move_up(Vdm *var)
{
	var->ness_y = var->ness_y + 60;
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, var->ness_x, var->ness_y);
}

void	ft_move_down(Vdm *var)
{
	var->ness_y = var->ness_y - 60;
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, var->ness_x, var->ness_y);
	printf("x=%d\ny=%d\n", var->ness_x, var->ness_y);
}

void	ft_move_left(Vdm *var)
{
	var->ness_x = var->ness_x - 60;
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, var->ness_x, var->ness_y);
}

void	ft_move_right(Vdm *var)
{
	var->ness_x = var->ness_x + 60;
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, var->ness_x, var->ness_y);
}
