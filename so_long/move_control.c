#include "so_long.h"

void	ft_move_up(T_Var *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->ness, 0, -80);
}

void	ft_move_down(T_Var *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->ness, 0, 80);
}

void	ft_move_left(T_Var *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->ness, -80, 0);
}

void	ft_move_right(T_Var *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->ness, 80, 0);
}
