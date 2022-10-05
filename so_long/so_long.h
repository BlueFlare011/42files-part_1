/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:54:38 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/05 11:50:46 by socana-b         ###   ########.fr       */
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

typedef struct s_var{
	char	**map;
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	void	*floor;
	void	*object;
	void	*exit;
	void	*ness;
	void	*hole;
	int		width;
	int		height;
	int		ness_x;
	int		ness_y;
	int		num_obj;
	int		exit_bool;
	int		steps;
}t_Var;

typedef struct s_valid{
	int	ness;
	int	obj;
	int	exit;
	int	hole;
	int	is_valid;
}t_Valid;

int		valid_map(int argc, char **argv, t_Valid *valid, t_Var *var);
int		key_control(int keycode, t_Var *var);
void	create_window(t_Var *var);
void	ft_move(t_Var *var, int x, int y);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	create_images(t_Var *var);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	break_all(t_Var *var);
void	put_map_in_window(t_Var *var);
void	free_map(t_Var *var);
char	*fill_line_map(t_Var *var, t_Valid *valid, int fd);

#endif
