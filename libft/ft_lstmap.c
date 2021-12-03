/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:48:40 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 16:50:28 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*header;

	if (!lst || !f)
		return (0);
	header = NULL;
	while (lst)
	{
		if (!(new_list = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&header, (*del));
			return (0);
		}
		ft_lstadd_back(&header, new_list);
		lst = lst->next;
	}
	return (header);
}
