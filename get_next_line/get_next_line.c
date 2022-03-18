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
void	free_all_mem(char *str)
{
	free (str);
	str = NULL;
}

char	*fix_to_return(char *str, int *last)
{
	unsigned int	i;
	char			*aux;

	i = 0;
	while ((str[i] != '\n') && (str[i] != '\0'))
		i++;
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

char	*get_the_read(int fd, int start, char *line)
{
	char	*buffer;
	char	*line2;
	char	*aux;
	size_t	apt;

	if (start)
		line2 = ft_strdup("");
	else
		line2 = line;
	buffer = malloc (sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	apt = BUFFER_SIZE;
	while ((!contains(line2, '\n', 0)) && (apt == BUFFER_SIZE))
	{
		aux = line2;
		apt = read(fd, buffer, BUFFER_SIZE);
		if ((int)apt == -1)
		{
			free_all_mem(buffer);
			free_all_mem(aux);
			return (NULL);
		}
		line2 = ft_strjoin(line2, buffer, apt);
		free_all_mem(aux);
	}
	free_all_mem(buffer);
	return (line2);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*aux;
	char		*result;
	int			last;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (line)
	{
		aux = line;
		line = ft_strdup(line + contains(line, '\n', 1) + 1);
		line = get_the_read(fd, 0, line);
		if (aux[0] != '\0')
			free_all_mem(aux);
	}
	else
		line = get_the_read(fd, 1, line);
	last = 0;
	if (!line)
		return (NULL);
	if (line[0] == '\0'){
		free(line);
		return NULL;}
	result = fix_to_return(line, &last);
	if (last)
	{
		free(line);
		line = NULL;
	}
	return (result);
}
