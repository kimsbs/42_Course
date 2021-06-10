/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:11:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 21:13:43 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	push_a(t_list **a, t_list **b)
{
	int		tmp;

	if(*b)
		return ;
	tmp = (*b)->index;
	rm_front(b);
	add_front(a, tmp);
}

void	push_b(t_list **a, t_list **b)
{
	int		tmp;

	if(*a)
		return ;
	tmp = (*a)->index;
	rm_front(a);
	add_front(b, tmp);
}
