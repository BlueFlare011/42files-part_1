#include "so_long.h"
/*
	CHAR = 'P',
	FLOOR = '0',
	HOLE = '1',
	OBJ = 'C',
	EXIT = 'E'
*/

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
	char	*line;
	char	*aux;

	file = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		valid->is_valid = 0;
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		aux = file;
		file = ft_strjoin(file, line);
		free(aux);
		free(line);
		line = get_next_line(fd);
		var->size_y++;
	}
	free(line);
	var->map = ft_split(file, '\n');
	free(file);
	close(fd);
}

int	valid_map(int argc, char **argv, t_Valid *valid, t_Var *var)
{
	valid->is_valid = 1;
	var->size_x = 0;
	var->size_y = 0;
	valid->ness = 0;
	valid->obj = 0;
	valid->exit = 0;
	if ((argc == 2)
		&& ((ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4)) == 0))
	{
		fill_map(argv[1], valid, var);
		if (valid->is_valid)
			map_reader(valid, var);
		if ((valid->exit != 1) || (valid->ness != 1) || (valid->obj <= 0))
			valid->is_valid = 0;
	}
	else
		valid->is_valid = 0;
	return (valid->is_valid);
}
