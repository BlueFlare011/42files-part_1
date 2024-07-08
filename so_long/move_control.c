/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:01:37 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/05 12:10:15 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_backend(t_Var *var, int x, int y)
{
	int	i;
	int	j;

	i = (var->ness_y + y) / 80;
	j = (var->ness_x + x) / 80;
	if (var->map[i][j] == OBJ)
	{
		var->map[i][j] = '0';
		var->num_obj++;
	}
	if ((var->map[i][j] == EXIT) && (var->num_obj == var->exit_bool))
	{
		printf("%d\n", ++var->steps);
		return (2);
	}
	if (var->map[i][j] != HOLE)
	{
		printf("%d\n", ++var->steps);
		return (1);
	}
	return (0);
}

void	ft_move(t_Var *var, int x, int y)
{
	if (move_backend(var, x, y) == 1)
	{
		mlx_put_image_to_window(var->mlx, var->win, var->floor,
			var->ness_x, var->ness_y);
		if (var->map[var->ness_y / 80][var->ness_x / 80] == EXIT)
			mlx_put_image_to_window(var->mlx, var->win, var->exit,
				var->ness_x, var->ness_y);
		var->ness_y += y;
		var->ness_x += x;
		mlx_put_image_to_window(var->mlx, var->win, var->ness,
			var->ness_x, var->ness_y);
	}
	else if (!move_backend(var, x, y)){}
	else
	{
		break_all(var);
		exit(1);
	}
}
