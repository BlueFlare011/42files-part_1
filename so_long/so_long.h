#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../Libft/libft.h"
# include <mlx.h>

enum {
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3,
};

typedef struct{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		weight;
	int		height;
}Vdm;

#endif