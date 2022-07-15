/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:23:03 by socana-b          #+#    #+#             */
/*   Updated: 2021/10/19 12:23:05 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (!lst)
		return (NULL);
	while ((lst->next) == NULL)
	{
		*f(lst);
		del(lst);
		lst = lst->next;
	}
	return (lst);
}
