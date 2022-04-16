#include "so_long.h"

static int	move_backend(t_Var *var, int x, int y)
{
	int i;
	int	j;

	i = (var->ness_y + y) / 80;
	j = (var->ness_x + x) / 80;
	if (var->map[i][j] == OBJ)
	{
		var->map[i][j] = '0';
		var->num_obj++;
	}
	if ((var->map[i][j] == EXIT) && (var->num_obj == var->exit_bool))
		return (2);
	if (var->map[i][j] != HOLE)
		return (1);
	return (0);
}

void	ft_move_up(t_Var *var)
{
	int f;

	f = move_backend(var, 0, -80);
	if (f)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->floor, var->ness_x, var->ness_y);
		if (var->map[var->ness_y/80][var->ness_x/80] == EXIT)
			mlx_put_image_to_window(var->mlx, var->win, var->exit, var->ness_x, var->ness_y);
		var->ness_y -= 80;
		mlx_put_image_to_window(var->mlx, var->win, var->ness, var->ness_x, var->ness_y);
	}
	if (f == 2)
	{
		break_all(var);
		exit(1);
	}
}

void	ft_move_down(t_Var *var)
{
	int f;

	f = move_backend(var, 0, 80);
	if (f)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->floor, var->ness_x, var->ness_y);
		if (var->map[var->ness_y / 80][var->ness_x / 80] == EXIT)
			mlx_put_image_to_window(var->mlx, var->win, var->exit, var->ness_x, var->ness_y);
		var->ness_y += 80;
		mlx_put_image_to_window(var->mlx, var->win, var->ness, var->ness_x, var->ness_y);
	}
	if (f == 2)
	{
		break_all(var);
		exit(1);
	}
}

void	ft_move_left(t_Var *var)
{
	int f;

	f = move_backend(var, -80, 0);
	if (f)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->floor, var->ness_x, var->ness_y);
		if (var->map[var->ness_y / 80][var->ness_x / 80] == EXIT)
			mlx_put_image_to_window(var->mlx, var->win, var->exit, var->ness_x, var->ness_y);
		var->ness_x -= 80;
		mlx_put_image_to_window(var->mlx, var->win, var->ness, var->ness_x, var->ness_y);
	}
	if (f >= 2)
	{
		break_all(var);
		exit(1);
	}
}

void	ft_move_right(t_Var *var)
{
	int f;

	f = move_backend(var, 80, 0);
	if (f)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->floor, var->ness_x, var->ness_y);
		if (var->map[var->ness_y/80][var->ness_x/80] == EXIT)
			mlx_put_image_to_window(var->mlx, var->win, var->exit, var->ness_x, var->ness_y);
		var->ness_x += 80;
		mlx_put_image_to_window(var->mlx, var->win, var->ness, var->ness_x, var->ness_y);
	}
	if (f >= 2)
	{
		break_all(var);
		exit(1);
	}
}
