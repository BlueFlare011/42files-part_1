/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:20:04 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 11:18:22 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*saux;
	unsigned int	i;

	i = 0;
	saux = s;
	while (i < n)
	{
		saux[i] = '\0';
		i++;
	}
}