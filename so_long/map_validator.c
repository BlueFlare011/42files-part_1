#include "so_long.h"

int line_contains(char *line, int x)
{
	
}

void map_lenghts(char *path, int *x, int *y)
{
	int		fd;
	char	*line;
	char	*aux;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	*x = ft_strlen(line) - 1;
	while (line)
	{
		aux = line;
		line = get_next_line(fd);
		free(aux);
		*y = *y + 1;
	}
	free(line);
	close(fd);
}

int	map_reader(char *path, int x, int y)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY);
	while (i < y)
	{
		line = get_next_line(fd);
		line_contains(line, x);
		i++;
	}
	close (fd);
}

int validMap(int argc, char **argv)
{
	int	valid;
	int x;
	int y;

	valid = 0;
	x = 0;
	y = 0;
	if ((argc == 2) && ((ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4)) == 0))
	{
		map_lenghts(argv[1], &x, &y);
		map_reader(argv[1], x, y);
	}
	return (valid);
}
