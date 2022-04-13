#include "so_long.h"
/*
	CHAR = 'P',
	FLOOR = '0',
	HOLE = '1',
	OBJ = 'C',
	EXIT = 'E'
*/
void	line_contains(T_Var *var, T_Valid *valid, int i)
{
	int	j;

	j = 0;
	valid->hole = 0;
	while ((j <= var->size_x) && valid->isValid)
	{
		if (((j == 0) || (j == var->size_x - 1)) && var->map[i][j] != HOLE)
			valid->isValid = 0;
		if (var->map[i][j] == CHAR)
			valid->ness++;
		else if (var->map[i][j] == HOLE)
			valid->hole++;
		else if (var->map[i][j] == OBJ)
			valid->obj++;
		else if (var->map[i][j] == EXIT)
			valid->exit++;
		j++;
	}
	if (((i == 0) || (i == var->size_y - 1)) && (valid->hole != var->size_x))
		valid->isValid = 0;
}

void	map_reader(T_Valid *valid, T_Var *var)
{
	int	i;

	i = 0;
	var->size_x = ft_strlen(var->map[i]);
	while (i < var->size_y && valid->isValid)
	{
		if ((int)ft_strlen(var->map[i]) != var->size_x)
			valid->isValid = 0;
		else
			line_contains(var, valid, i);
		i++;
	}
}

void	fill_map(char *path, T_Valid *valid, T_Var *var)
{
	int		fd;
	char	*file;
	char	*line;
	char	*aux;

	file = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		valid->isValid = 0;
		return ;
	}
	line = get_next_line(fd);
	while(line)
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

int	valid_map(int argc, char **argv, T_Valid *valid, T_Var *var)
{
	valid->isValid = 1;
	var->size_x = 0;
	var->size_y = 0;
	valid->ness = 0;
	valid->obj = 0;
	valid->exit = 0;
	if ((argc == 2)
		&& ((ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4)) == 0))
	{
		fill_map(argv[1], valid, var);
		if (valid->isValid)
			map_reader(valid, var);
	}
	else
		valid->isValid = 0;
	return (valid->isValid);
}
