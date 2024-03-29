/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: socana-b <socana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:23:03 by socana-b          #+#    #+#             */
/*   Updated: 2022/09/24 11:19:45 by socana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*auxl;

	if (!lst)
		return (NULL);
	result = NULL;
	auxl = ft_lstnew((*f)(lst->content));
	while (lst != NULL)
	{
		ft_lstadd_back(&result, auxl);
		lst = lst->next;
		if (lst != NULL)
			auxl = ft_lstnew((*f)(lst->content));
	}
	if (auxl == NULL)
	{
		while (lst != NULL)
		{
			lst = lst->next;
			del(auxl->content);
			free(auxl);
		}
		result = NULL;
	}
	return (result);
}
