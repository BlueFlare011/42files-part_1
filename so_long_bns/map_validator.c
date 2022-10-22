/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:40:07 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/22 11:11:31 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_contains(t_win *win, t_Valid *valid, int i)
{
	int	j;

	j = 0;
	valid->hole = 0;
	while ((j < win->size_x) && valid->is_valid)
	{
		if (((j == 0) || (j == win->size_x - 1)) && win->map[i][j] != HOLE)
			valid->is_valid = 0;
		if (win->map[i][j] == CHAR)
			valid->ness++;
		else if (win->map[i][j] == HOLE)
			valid->hole++;
		else if (win->map[i][j] == OBJ)
			valid->obj++;
		else if (win->map[i][j] == EXIT)
			valid->exit++;
		else if (win->map[i][j] != FLOOR)
			valid->is_valid = 0;
		j++;
	}
	if (((i == 0) || (i == win->size_y - 1)) && (valid->hole != win->size_x))
		valid->is_valid = 0;
}

void	map_reader(t_Valid *valid, t_win *win)
{
	int	i;

	valid->ness = 0;
	valid->obj = 0;
	valid->exit = 0;
	i = 0;
	win->size_x = ft_strlen(win->map[i]);
	while (i < win->size_y && valid->is_valid)
	{
		if ((int)ft_strlen(win->map[i]) != win->size_x)
			valid->is_valid = 0;
		else
			line_contains(win, valid, i);
		i++;
	}
}

void	fill_map(char *path, t_Valid *valid, t_win *win)
{
	int		fd;
	char	*file;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: El mapa seleccionado no existe\n", 38);
		valid->is_valid = 0;
		close(fd);
		return ;
	}
	file = fill_line_map(win, valid, fd);
	win->map = ft_split(file, '\n');
	if (!valid->is_valid)
		write(2, "Error: El mapa no cumple con los requisitos\n", 44);
	free(file);
	close(fd);
}

int	valid_map(int argc, char **argv, t_Valid *valid, t_win *win)
{
	valid->is_valid = 1;
	win->size_x = 0;
	win->size_y = 0;
	if ((argc == 2)
		&& ((ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4)) == 0))
	{
		fill_map(argv[1], valid, win);
		if (valid->is_valid)
		{
			map_reader(valid, win);
			if ((valid->exit != 1) || (valid->ness != 1) || (valid->obj <= 0))
				valid->is_valid = 0;
			if (!valid->is_valid)
			{
				write(2, "Error: El mapa no cumple con los requisitos\n", 44);
				free_map(win);
			}
		}
	}
	else
	{
		write(2, "Error: El argumento es erroneo\n", 31);
		valid->is_valid = 0;
	}
	return (valid->is_valid);
}
