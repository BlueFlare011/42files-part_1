/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:59:56 by socana-b          #+#    #+#             */
/*   Updated: 2021/10/05 11:59:57 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if ((!lst) && (!*lst))
		return ;
	while (((*lst)->next) == NULL)
	{
		free(*lst);
		del(*lst);
		*lst = (*lst)->next;
	}
	lst = NULL;
	free(lst);
}
