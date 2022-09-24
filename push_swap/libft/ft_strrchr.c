/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:19:16 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 11:22:09 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	aux;

	aux = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i] != aux) && (s[i] != s[0]))
		i--;
	if (s[i] == aux)
		return ((char *)(s + i));
	else
		return (NULL);
}
