#include "so_long.h"

void	ft_move_up(T_Var *var)
{
	if (var->ness_y - 80 >= 0)
	{
		var->ness_y -= 80;
		mlx_put_image_to_window(var->mlx, var->win, var->ness, var->ness_x, var->ness_y);
		mlx_put_image_to_window(var->mlx, var->win, var->floor, var->ness_x, var->ness_y + 80);
	}
	
}

void	ft_move_down(T_Var *var)
{
	if (var->ness_y + 80 < var->size_y * 80)
	{
		var->ness_y += 80;
		mlx_put_image_to_window(var->mlx, var->win, var->ness, var->ness_x, var->ness_y);
		mlx_put_image_to_window(var->mlx, var->win, var->floor, var->ness_x, var->ness_y - 80);
	}
	
}

void	ft_move_left(T_Var *var)
{
	if (var->ness_x - 80 >= 0)
	{
		var->ness_x -= 80;
		mlx_put_image_to_window(var->mlx, var->win, var->ness, var->ness_x, var->ness_y);
		mlx_put_image_to_window(var->mlx, var->win, var->floor, var->ness_x + 80, var->ness_y);
	}
}

void	ft_move_right(T_Var *var)
{
	if (var->ness_x + 80 < var->size_x * 80)
	{
		var->ness_x += 80;
		mlx_put_image_to_window(var->mlx, var->win, var->ness, var->ness_x, var->ness_y);
		mlx_put_image_to_window(var->mlx, var->win, var->floor, var->ness_x - 80, var->ness_y);
	}
}
