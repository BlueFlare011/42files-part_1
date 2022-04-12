#include "so_long.h"
//Si el mapa esta cerrado pero los extremos son floor?
/*
	CHAR = 'P',
	FLOOR = '0',
	HOLE = '1',
	OBJ = 'C',
	EXIT = 'E'
*//*
void	line_contains(char *line, T_Valid *valid, int i)
{
	int	j;

	j = 0;
	valid->hole = 0;
	while ((j <= valid->size_x) && valid->isValid)
	{
		if (((j == 0) || (j == valid->size_x - 1)) && line[j] != HOLE)
			valid->isValid = 0;
		if (line[j] == CHAR)
			valid->ness++;
		else if (line[j] == HOLE)
			valid->hole++;
		else if (line[j] == OBJ)
			valid->obj++;
		else if (line[j] == EXIT)
			valid->exit++;
		j++;
	}
	if (((i == 0) || (i == valid->size_y)) && (valid->hole != valid->size_x))
		valid->isValid = 0;
}*/

void	map_lenghts(char *path, T_Valid *valid, T_Var *var)
{
	int		fd;
	char	*line;
	char	*aux;

	fd = open(path, O_RDONLY);
	if (fd >= 0)
	{
		line = get_next_line(fd);
		var->size_x = ft_strlen(line) - 1;
		while (line)
		{
			aux = line;
			line = get_next_line(fd);
			free(aux);
			var->size_y++;
		}
		free(line);
	}
	else
		valid->isValid = 0;
	close(fd);
}

void	map_fill(char *path, T_Valid *valid, T_Var *var)
{
	int		i;
	int		fd;

	var->map = malloc(sizeof(char *) * valid->size_y);
	if (!var->map)
		return ;
	i = 0;
	fd = open(path, O_RDONLY);
	while ((i < var->size_y) && valid->isValid)
	{
		var->map[i] = get_next_line(fd);
		if (((int)ft_strlen(var->map[i]) - 1 != var->size_x) && (i != var->size_y - 1))
			valid->isValid = 0;
		else if (((int)ft_strlen(var->map[i]) != var->size_x) && (i == var->size_y - 1))
			valid->isValid = 0;
		i++;
	}
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
		map_lenghts(argv[1], valid, var);
		if (valid->isValid)
			map_fill(argv[1], valid, var);
		for (int i = 0; i < var->size_y; i++)
			printf("%s", var->map[i]);
	}
	else
		valid->isValid = 0;
	return (valid->isValid);
}
