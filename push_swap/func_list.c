/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:10:17 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/07 15:09:35 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_list	*make_node(int data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		exit(-1);
	new_node->index = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_front(t_list **header, int data)
{
	t_list	*new_node;
	t_list	*last;

	new_node = make_node(data);
	if (!*header)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*header = new_node;
	}
	else
	{
		last = (*header)->prev;
		new_node->prev = last;
		last->next = new_node;
		(*header)->prev = new_node;
		new_node->next = (*header);
		*header = new_node;
	}
}

void	add_back(t_list **header, int data)
{
	t_list	*new_node;
	t_list	*last;

	new_node = make_node(data);
	if (!*header)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*header = new_node;
	}
	else
	{
		last = (*header)->prev;
		new_node->prev = last;
		last->next = new_node;
		(*header)->prev = new_node;
		new_node->next = (*header);
	}
}

void	rm_front(t_list **header)
{
	t_list	*last;
	t_list	*rm;

	rm = *header;
	if ((*header)->next != (*header))
	{
		last = (*header)->prev;
		last->next = (*header)->next;
		(*header)->next->prev = last;
		*header = (*header)->next;
		free(rm);
	}
	else
	{
		free(*header);
		*header = NULL;
	}
}
