/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:47:46 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 12:59:51 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/my_bonus.h"

void	check_leaks(void)
{
	system("leaks my_checker");
}

int	valid_move(char *move)
{
	int	l;

	l = ft_strlen(move);
	if (l > 3)
		return (0);
	if (ft_strncmp(move, "ra", l) == 0 || ft_strncmp(move, "rb", l) == 0
		|| ft_strncmp(move, "rr", l) == 0)
		return (1);
	if (ft_strncmp(move, "pa", l) == 0 || ft_strncmp(move, "pb", l) == 0)
		return (1);
	if (ft_strncmp(move, "rra", l) == 0 || ft_strncmp(move, "rrb", l) == 0
		|| ft_strncmp(move, "rrr", l) == 0)
		return (1);
	if (ft_strncmp(move, "sa", l) == 0 || ft_strncmp(move, "sb", l) == 0
		|| ft_strncmp(move, "ss", l) == 0)
		return (1);
	return (0);
}

int	check_moves(char **moves)
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	while (moves[i] && valid)
	{
		if (!valid_move(moves[i]))
			valid = 0;
		i++;
	}
	return (valid);
}

char	**read_moves(void)
{
	char	*aux;
	char	*move_line;
	char	*scan_in;
	char	**result;

	move_line = ft_strdup("");
	scan_in = (char *)malloc(sizeof(char) * 1);
	if (!move_line || !scan_in)
		return (NULL);
	while (1)
	{
		aux = move_line;
		if (!read(0, scan_in, 1))
			break ;
		move_line = ft_strjoin(move_line, scan_in);
		free(aux);
	}
	free(scan_in);
	result = ft_split(move_line, '\n');
	free(move_line);
	return (result);
}

void	crear_stack(t_stack *a, t_stack *b)
{
	*a = NULL;
	*b = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**moves;
	atexit(check_leaks);
	if (argc > 1)
	{
		crear_stack(&a, &b);
		if (args_settings(argv, argc, &a))
		{
			moves = read_moves();
			if (check_moves(moves))
			{
				sort_stack(&a, &b, moves);
				if (is_sorted(&a))
					write(1, "OK\n", 3);
				else
					write(1, "KO\n", 3);
			}
			else
				write(2, "Error\n", 6);
			delete_all(&a, moves);
		}
		delete_stack(&a);
	}
	return (0);
}
