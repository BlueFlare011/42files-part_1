/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:27:41 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 11:18:06 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static long long int	atoi2(const char *str, long long int i)
{
	long long int	n;

	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (long long int)str[i] - 48;
		i++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	long long int			i;
	long long int			s;
	unsigned long long int	number;

	i = 0;
	s = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	number = atoi2(str, i);
	if ((number > 2147483647) && (s > 0))
		return (-1);
	else if ((number > 2147483648) && (s < 0))
		return (-1);
	return (number * s);
}
