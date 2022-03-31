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

#include "get_next_line_bonus.h"

void	free_all_mem(char *str)
{
	free (str);
	str = NULL;
}

char	*fix_to_return(char *str, int *last)
{
	unsigned int	i;
	char			*aux;

	if ((!str) || (*str == '\0'))
	{
		free_all_mem(str);
		return (NULL);
	}
	i = contains(str, '\n', 1);
	aux = malloc(sizeof(char) * (i + 2));
	if (!aux)
		return (NULL);
	i = 0;
	while ((str[i] != '\n') && (str[i] != '\0'))
	{
		aux[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		aux[i++] = '\n';
	else
		*(last) = 1;
	aux[i] = '\0';
	return (aux);
}

char	*get_the_read(int fd, char *line)
{
	char	*buffer;
	char	*line2;
	int		apt;

	if (!line)
		line = ft_strdup("");
	buffer = malloc (sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (!contains(line, '\n', 0))
	{
		line2 = line;
		apt = read(fd, buffer, BUFFER_SIZE);
		if ((apt == 0) || (apt == -1))
			break ;
		line = ft_strjoin(line, buffer, apt);
		free_all_mem(line2);
	}
	free_all_mem(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[MAX_FD];
	char		*aux;
	char		*result;
	int			last;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (line[fd])
	{
		aux = line[fd];
		line[fd] = ft_strdup(line[fd] + contains(line[fd], '\n', 1) + 1);
		line[fd] = get_the_read(fd, line[fd]);
		if (aux[0] != '\0')
			free_all_mem(aux);
	}
	else
		line[fd] = get_the_read(fd, line[fd]);
	last = 0;
	result = fix_to_return(line[fd], &last);
	if (last)
	{
		free(line[fd]);
		line[fd] = NULL;
	}
	return (result);
}
