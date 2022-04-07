#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
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

typedef struct{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;

	void	*floor;
	void	*object;
	void	*stair;
	void	*ness;
	void	*hole;
	int		width;
	int		height;
}T_Var;

int		validMap(int argc, char **argv);
int		key_control(int keycode, T_Var *var);
void	createWindow(T_Var *var);
void	ft_move_up(T_Var *var);
void	ft_move_down(T_Var *var );
void	ft_move_left(T_Var *var );
void	ft_move_right(T_Var *var);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif