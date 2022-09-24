/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:56:39 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 11:20:38 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, unsigned long int len)
{
	unsigned int	i;
	char			*baux;

	baux = b;
	i = 0;
	while (i < len)
	{
		baux[i] = c;
		i++;
	}
	return (b);
}
