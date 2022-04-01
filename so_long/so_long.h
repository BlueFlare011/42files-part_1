#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../Libft/libft.h"
# include <mlx.h>

enum
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

typedef struct{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		width;
	int		height;
	int		ness_x;
	int		ness_y;
}Vdm;

int		ft_error();
void	createWindow(Vdm *var);
void	ft_move_up(Vdm *var);
void	ft_move_down(Vdm *var);
void	ft_move_left(Vdm *var);
void	ft_move_right(Vdm *var);
#endif