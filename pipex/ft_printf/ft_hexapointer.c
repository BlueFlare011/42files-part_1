/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexapointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:26:04 by socana-b          #+#    #+#             */
/*   Updated: 2021/11/11 10:26:06 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

int	hexapointer(unsigned long n, char *base)
{
	if (n < 16)
		return (write (1, &base[n], 1));
	else
		return (hexapointer((n / 16), "0123456789abcdef")
			+ write(1, &base[n % 16], 1));
}
