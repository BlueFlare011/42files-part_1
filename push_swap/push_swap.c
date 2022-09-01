/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blueflare <blueflare@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:07:23 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/01 11:59:44 by blueflare        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	check_leaks(void)
{
	system("leaks push_swap");
}*/

void	crear_stack(t_stack *a, t_stack *b)
{
	a->init = NULL;
	b->init = NULL;
	a->final = NULL;
	b->final = NULL;
	a->len = 0;
	a->len = 0;
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
			high_five(&a, &b);/*
			printf("Pila ordenada:\n");
			print_stack(&a);
			write(1, "_________________________________________\n", 42);
			print_stack(&b);*/
		}
		delete_stack(&a);
		delete_stack(&b);
	}
	return (0);
}

//-2147483648
