/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:21:12 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 21:30:49 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	print_list(t_list *a, t_list *b)
{
	t_list	*a_tmp;
	t_list	*b_tmp;
	char	a_data;
	char	b_data;
	char	a_prev;
	char	b_prev;

	a_prev = '\0';
	b_prev = '\0';
	a_tmp = a;
	b_tmp = b;
	while(a_tmp->next != a || b_tmp->next != b)
	{
		if(a_tmp->next != a)
			a_data = a->index + '0';
		else
			a_data = ' ';
		if(b_tmp->next != b)
		{
			b_data = b->index + '0';
		}
		else
			b_data = ' ';
		write(1, &a_data, 1);
		write(1, " ", 1);
		write(1, &b_data, 1);
		write(1, "\n", 1);
		if(a_tmp->next != a)
			a_tmp = a_tmp->next;
		if(b_tmp->next != b)
			b_tmp = b_tmp->next;
	}
}
