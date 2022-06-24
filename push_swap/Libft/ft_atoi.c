/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:27:41 by socana-b          #+#    #+#             */
/*   Updated: 2021/09/16 08:27:44 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	is_number(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

static long long int	atoi2(const char *str, long long int i)
{
	long long int	n;

	n = 0;
	while (is_number(str[i]))
	{
		n = (n * 10) + (long long int)str[i] - 48;
		i++;
	}
	return (n);
}

static long long int	space(const char *str, long long int i)
{
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long long int			i;
	long long int			s;
	unsigned long long int	number;

	i = 0;
	s = 1;
	if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i = space(str, i);
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	number = atoi2(str, i);
	if ((number > 9223372036854775807) && (s > 0))
		return (-1);
	else if ((number > 9223372036854775807) && (s < 0))
		return (0);
	return (number * s);
}
