/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:10:17 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 21:21:40 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_list	*make_node(int data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->index = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_list	*find_last(t_list *header)
{
	t_list	*tmp;

	tmp = header;
	while(tmp->next != header)
		tmp = tmp->next;
	return (tmp);
}

void	add_front(t_list **header, int data)
{
	t_list	*new_node;
	t_list	*last;

	new_node = make_node(data);
	if(!*header)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*header = new_node;
	}
	else
	{
		last = find_last(*header);
		(*header)->prev = new_node;
		new_node->next = *header;
		last->next = new_node;
		new_node->prev = last;
		*header = new_node;
	}
}

void	rm_front(t_list **header)
{
	t_list	*last;
	t_list	*rm;

	rm = *header;
	last = find_last(*header);
	last->next = (*header)->next;
	(*header)->next->prev = last;
	*header = (*header)->next;
	free(rm);
}
