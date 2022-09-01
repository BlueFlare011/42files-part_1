/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:00:15 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/01 14:33:51 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	repeat(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if ((ft_strlen(args[i]) == ft_strlen(args[j]))
				&& (ft_strncmp(args[i], args[j], ft_strlen(args[i])) == 0))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	valid_num(char *arg)
{
	int	i;
	int	flag;

	i = 0;
	flag = arg[0] != '\0';
	while (arg[i] && flag)
	{
		if ((i == 0) && ((arg[i] == '-') || (arg[i] == '+'))) //Tiene que admitir '+'
			i++;
		if (!ft_isdigit(arg[i]))
			flag = 0;
		i++;
	}
	return (flag);
}

int	error_manager(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!valid_num(args[i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if ((ft_atoi(args[i]) == -1) && ft_strlen(args[i]) != 2)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (repeat(args));
}
