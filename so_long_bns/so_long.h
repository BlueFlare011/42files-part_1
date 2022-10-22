/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:54:38 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/22 11:15:04 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"
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

typedef struct s_ness{
	void	*front_1;
	void	*front_2;
	void	*back_1;
	void	*back_2;
	void	*left;
	void	*walk_l;
	void	*right;
	void	*walk_r;
	int		ness_x;
	int		ness_y;
	int		steps;
}t_ness;

typedef struct s_obj{
	void	*object;
	void	*obj_open;
	int		num_obj;
}t_obj;

typedef struct s_exit{
	void	*closed;
	void	*open;
	int		exit_bool;
}t_exit;

typedef struct s_win{
	char	**map;
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	void	*floor;
	void	*hole;
	t_ness	*ness;
	t_obj	*obj;
	t_exit	*exit;
	int		img_size;
}t_win;

typedef struct s_valid{
	int	ness;
	int	obj;
	int	exit;
	int	hole;
	int	is_valid;
}t_Valid;

int		valid_map(int argc, char **argv, t_Valid *valid, t_win *var);
int		key_control(int keycode, t_win *var);
void	create_window(t_win *var);
void	ft_move(t_win *var, int x, int y);
void	create_images(t_win *var);
void	break_all(t_win *var);
void	put_map_in_window(t_win *var);
void	free_map(t_win *var);
char	*fill_line_map(t_win *var, t_Valid *valid, int fd);

#endif
