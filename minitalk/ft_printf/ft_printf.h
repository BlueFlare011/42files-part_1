/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:46:20 by socana-b          #+#    #+#             */
/*   Updated: 2021/10/22 12:46:21 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
void	string(char *str, int **i);
void	pointer(void *p, int **i);
int		unsign(unsigned long n, char *base);
int		hexadecimal(unsigned int n, char *base);
int		upperhexadecimal(unsigned int n, char *base);
int		number(int n, char *base);
int		hexapointer(unsigned long n, char *base);

#endif