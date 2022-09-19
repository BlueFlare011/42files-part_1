/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:07:23 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/19 17:48:49 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	crear_stack(t_stack *a, t_stack *b)
{
	a->init = NULL;
	b->init = NULL;
	a->final = NULL;
	b->final = NULL;
	a->len = 0;
	b->len = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		crear_stack(&a, &b);
		if (args_settings(argv, argc, &a))
		{
			set_id(&a);
			by_chunks(&a, &b);
		}
		delete_stack(&a);
		delete_stack(&b);
	}
	return (0);
}
