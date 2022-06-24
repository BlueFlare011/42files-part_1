/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:47:02 by socana-b          #+#    #+#             */
/*   Updated: 2021/11/09 12:47:04 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexadecimal(unsigned int n, char *base)
{
	if (n < 16)
		return (write (1, &base[n], 1));
	else
		return (hexadecimal((n / 16), "0123456789abcdef")
			+ write(1, &base[n % 16], 1));
}

int	upperhexadecimal(unsigned int n, char *base)
{
	if (n < 16)
		return (write (1, &base[n], 1));
	else
		return (upperhexadecimal((n / 16), "0123456789ABCDEF")
			+ write(1, &base[n % 16], 1));
}

void	pointer(void *p, int **i)
{
	write(1, "0x", 2);
	(**i) = (**i) + hexapointer((unsigned long)p, "0123456789abcdef");
	(**i) = (**i) + 2;
}

int	unsign(unsigned long n, char *base)
{
	if (n < 10)
		return (write (1, &base[n], 1));
	else
		return (unsign((n / 10), "0123456789") + write(1, &base[n % 10], 1));
}

int	number(int n, char *base)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		return (write(1, "-", 1) + number(n, "0123456789"));
	}
	if (n < 10)
		return (write (1, &base[n], 1));
	else
		return (number((n / 10), "0123456789") + write(1, &base[n % 10], 1));
}
