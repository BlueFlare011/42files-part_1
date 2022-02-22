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

void cleaning(char *line)
{
	free(line);
	line = NULL;
}

char *clean_static(char **line, int fd)
{
	char			*aux;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (line[fd][i] != '\n')
		i++;
	j = ++i;
	while (line[fd][j] != '\0')
		j++;
	aux = malloc(sizeof(char) * (j + 1));
	if (!aux)
		return (NULL);
	j = 0;
	while (line[fd][i] != '\0')
	{
		aux[j] = line[fd][i];
		j++;
		i++;
	}
	aux[j] = '\0';
	return (aux);
}

char	*to_return(char **line, int fd)
{
	unsigned int	i;
	char			*aux;

	i = 0;	
	while ((line[fd][i] != '\n') && (line[fd][i] != '\0'))
		i++;
	aux = malloc(sizeof(char) * (i + 2));
	if (!aux)
		return (NULL);
	i = 0;
	while ((line[fd][i] != '\n') && (line[fd][i] != '\0'))
	{
		aux[i] = line[fd][i];
		i++;
	}
	if (line[fd][i] == '\0')
		aux[i] = '\0';
	else
	{
		aux[i++] = '\n';
		aux[i] = '\0';
	}
	return (aux);
}

char	*get_the_read(char **line, char *buffer, int fd)
{
	size_t	flag;

	if (!line[fd])
		line[fd] = ft_strdup("");
	else
		line[fd] = ft_strdup(clean_static(line, fd));
	flag = BUFFER_SIZE;
	while (!contains(buffer, '\n') && (flag == BUFFER_SIZE))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		line[fd] = ft_strjoin(line[fd], buffer, flag);
	}
	if (((int)flag == 0))
	{
		cleaning(line[fd]);
		cleaning(buffer);
		return (NULL);
	}
	return (to_return(line, fd));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*one_line;
	static char	*line[MAX_FD];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	one_line = get_the_read(line, buffer, fd);
	if (!one_line)
		return (NULL);
	return (one_line);
}
