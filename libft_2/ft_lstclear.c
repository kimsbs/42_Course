/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:12:46 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 15:46:49 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *move;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		move = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = move;
	}
}
