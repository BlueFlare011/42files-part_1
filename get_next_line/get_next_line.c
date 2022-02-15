/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:19:18 by socana-b          #+#    #+#             */
/*   Updated: 2021/12/02 12:19:20 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line[200];
	char		*buffer;
	size_t		flag;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	flag = BUFFER_SIZE;
	if (!line[fd])
		line[fd] = ft_strdup("");
	while ((!contains(line[fd], '\n') && (flag == BUFFER_SIZE)))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		line[fd] = ft_strjoin(line[fd], buffer, flag);
		buffer = NULL;
	}
	free(buffer);
	return (line[fd]);
}
