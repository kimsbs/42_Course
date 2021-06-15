/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:21:12 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/15 16:56:00 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	recursive_put(int data)
{
	int		tmp;
	char	out;
	if(data >= 10 || data <= -10)
		recursive_put(data/10);
	tmp = data % 10;
	if(tmp < 0)
		tmp *= -1;
	out = tmp + '0';
	write(1, &out, 1);
}

void	print_integer(int data)
{
	if(data < 0)
	{
		write(1, "-", 1);
		recursive_put(data);
	}
	else if(data == 0)
		write(1, "0", 1);
	else
		recursive_put(data);
}

void	print_list_solo(t_list *list)
{
	t_list	*head;

	head = list;
	if(!list)
		return ;
	while(list->next != head)
	{
		print_integer(list->index);
		write(1, " ", 1);
		list = list->next;
	}
	print_integer(list->index);
}

void	print_list(t_list *a, t_list *b)
{
	write(1, "a: ", 3);
	print_list_solo(a);
	write(1, "\n", 1);
	write(1, "b: ", 3);
	print_list_solo(b);
	write(1, "\n", 1);
}
