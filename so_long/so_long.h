#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <mlx.h>

enum
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

enum
{
	CHAR = 'P',
	FLOOR = '0',
	HOLE = '1',
	OBJ = 'C',
	EXIT = 'E'
};

typedef struct 
{
	void	*img;
	int		width;
	int		height;
	int		ness_x;
	int		ness_y;
}Ness;


typedef struct{
	void	*mlx;
	void	*mlx_win;
	int		size_x;
	int		size_y;
}Window;

int		ft_error();
void	createWindow(Window *var, Ness *ness);
void	ft_move_up(Window *var, Ness *ness);
void	ft_move_down(Window *var , Ness *ness);
void	ft_move_left(Window *var , Ness *ness);
void	ft_move_right(Window *var, Ness *ness);
#endif