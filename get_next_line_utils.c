/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:59:30 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/11 16:48:48 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void  ft_strcpy(char *s1, char *s2, int size)
{
  int move;
  move = 0;

  while(move < size)
  {
    s1[move] = s2[move];
    move++;
  }
  s1[move] = '\0';
}

t_list *lst_last(t_list *lst)
{
  while(lst->next)
    lst = lst->next;
  return (lst);
}

void	ft_lstadd_back(t_list **lst, char *content, int size)
{
	t_list *new;
  t_list *last;
  char *tmp;
  
  tmp = (char *)malloc(sizeof(char) * size + 1);
  ft_strcpy(tmp, content, size);
	new = ft_lstnew(tmp);
	if (!*lst)
		*lst = new;
	else
	{
	  last = lst_last(*lst);
		last->next = new;
	}
}

t_list	*ft_lstnew(char *content)
{
	t_list *new_list;

	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
