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

char *build_line(char *container)
{
	char	*line;
	int		i;

	i = 0;
	while ((container[i] != '\n') && (container[i] != '\0'))
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while ((container[i] != '\n') && (container[i] != '\0'))
	{
		line[i] = container[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	static char	*container;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!container)
		container = ft_strdup("");
	while ((read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE) && !contains(buffer, '\n'))
		container = ft_strjoin(container, buffer);
	container = ft_strjoin(container, buffer);
	line = build_line(container);
	free(buffer);
	return (line);
}