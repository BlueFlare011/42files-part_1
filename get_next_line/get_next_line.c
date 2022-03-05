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
#include <stdio.h>

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
	char		*aux;
	char		*line;
	size_t		flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	flag = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	if (!container)
		container = ft_strdup("");
	while ((!contains(container, '\n')) && (flag == BUFFER_SIZE))
	{
		free (container);
		flag = read(fd, buffer, BUFFER_SIZE);
		container = ft_strjoin(container, buffer, flag);
	}
	if (!flag)
		return (NULL);
	line = build_line(container);
	aux = container;
	container = ft_strdup(container + ft_strlen(line));
	free(aux);
	free(buffer);
	return (line);
}
