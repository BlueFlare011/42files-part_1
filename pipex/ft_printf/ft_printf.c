/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:12:27 by socana-b          #+#    #+#             */
/*   Updated: 2021/10/28 13:12:29 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(char *str, int **i)
{
	if (!str)
		(**i) = (**i) + write(1, "(null)", 6);
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			(**i) = (**i) + 1;
		}
	}
}

void	chose(char v, va_list arg, int *i)
{
	char	c;

	if ((v == 'i') || (v == 'd'))
		(*i) = (*i) + number(va_arg(arg, int), "0123456789");
	else if (v == 'c')
	{
		c = va_arg(arg, int);
		write (1, &c, 1);
		(*i) = (*i) + 1;
	}
	else if (v == 's')
		string(va_arg(arg, char *), &i);
	else if (v == 'x')
		(*i) = (*i) + hexadecimal(va_arg(arg, int), "0123456789abcdef");
	else if (v == 'X')
		(*i) = (*i) + upperhexadecimal(va_arg(arg, int), "0123456789ABCDEF");
	else if (v == 'p')
		pointer(va_arg(arg, void *), &i);
	else if (v == 'u')
		(*i) = (*i) + unsign(va_arg(arg, unsigned int), "0123456789");
	else if (v == '%')
		(*i) = (*i) + write (1, "%%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			chose(*(format + 1), arg, &i);
			format++;
		}
		else
		{
			write (1, format, 1);
			i++;
		}
		format++;
	}
	va_end(arg);
	return (i);
}
