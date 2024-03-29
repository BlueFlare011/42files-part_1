/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:11:12 by socana-b          #+#    #+#             */
/*   Updated: 2021/09/30 10:11:13 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	leng(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		i++;
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void recursive(char *result, int num, int i, int length, int limit)
{
	if (i == limit)
		result[i] = (char)num + 48;
	else
	{
		recursive(result, num / 10, i - 1, length, limit);
		result[i] = (char)((num % 10) + 48);
	}
}

char	*ft_itoa(int n)
{
	char	*num;
	int 	length;
	int		limit;

	if (n == -2147483648)
		return(ft_strdup("-2147483648"));
	length = leng(n);
	limit = 0;
	num = malloc (sizeof(char) * (length + 1));
	if (num == NULL)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		limit = 1;
		n *= -1;
	}
	recursive(num, n, length - 1, length, limit);
	num[length] = '\0';
	return (num);
}
