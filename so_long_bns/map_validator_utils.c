/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:30:53 by socana-b          #+#    #+#             */
/*   Updated: 2022/10/22 11:11:08 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*fill_line_map(t_win *win, t_Valid *valid, int fd)
{
	char	*line;
	char	*file;
	char	*aux;

	file = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			valid->is_valid = 0;
		aux = file;
		file = ft_strjoin(file, line);
		free(aux);
		free(line);
		line = get_next_line(fd);
		win->size_y++;
	}
	free(line);
	return (file);
}
