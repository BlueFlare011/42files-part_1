/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:40:07 by socana-b          #+#    #+#             */
/*   Updated: 2022/04/18 14:40:11 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_contains(t_Var *var, t_Valid *valid, int i)
{
	int	j;

	j = 0;
	valid->hole = 0;
	while ((j < var->size_x) && valid->is_valid)
	{
		if (((j == 0) || (j == var->size_x - 1)) && var->map[i][j] != HOLE)
			valid->is_valid = 0;
		if (var->map[i][j] == CHAR)
			valid->ness++;
		else if (var->map[i][j] == HOLE)
			valid->hole++;
		else if (var->map[i][j] == OBJ)
			valid->obj++;
		else if (var->map[i][j] == EXIT)
			valid->exit++;
		else if (var->map[i][j] != FLOOR)
			valid->is_valid = 0;
		j++;
	}
	if (((i == 0) || (i == var->size_y - 1)) && (valid->hole != var->size_x))
		valid->is_valid = 0;
}

void	map_reader(t_Valid *valid, t_Var *var)
{
	int	i;

	valid->ness = 0;
	valid->obj = 0;
	valid->exit = 0;
	i = 0;
	var->size_x = ft_strlen(var->map[i]);
	while (i < var->size_y && valid->is_valid)
	{
		if ((int)ft_strlen(var->map[i]) != var->size_x)
			valid->is_valid = 0;
		else
			line_contains(var, valid, i);
		i++;
	}
}

void	fill_map(char *path, t_Valid *valid, t_Var *var)
{
	int		fd;
	char	*file;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nEl mapa seleccionado no existe\n", 37);
		valid->is_valid = 0;
		close(fd);
		return ;
	}
	file = fill_line_map(var, valid, fd);
	var->map = ft_split(file, '\n');
	if (!valid->is_valid)
		write(1, "Error\nEl mapa no cumple con los requisitos\n", 43);
	free(file);
	close(fd);
}

int	valid_map(int argc, char **argv, t_Valid *valid, t_Var *var)
{
	valid->is_valid = 1;
	var->size_x = 0;
	var->size_y = 0;
	if ((argc == 2)
		&& ((ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4)) == 0))
	{
		fill_map(argv[1], valid, var);
		if (valid->is_valid)
		{
			map_reader(valid, var);
			if ((valid->exit != 1) || (valid->ness != 1) || (valid->obj <= 0))
				valid->is_valid = 0;
			if (!valid->is_valid)
			{
				write(1, "Error\nEl mapa no cumple con los requisitos\n", 43);
				free_map(var);
			}
		}
	}
	else
	{
		write(1, "Error\nEl argumento es erroneo\n", 30);
		valid->is_valid = 0;
	}
	return (valid->is_valid);
}
