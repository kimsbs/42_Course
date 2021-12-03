/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:11:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/20 18:59:43 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	push_a(t_list **a, t_list **b)
{
	int		tmp;

	if (!*b)
		return ;
	write(1, "pa\n", 3);
	tmp = (*b)->index;
	rm_front(b);
	add_front(a, tmp);
}

void	push_b(t_list **a, t_list **b)
{
	int		tmp;

	if (!*a)
		return ;
	write(1, "pb\n", 3);
	tmp = (*a)->index;
	rm_front(a);
	add_front(b, tmp);
}

long	ft_atoi(const char *str)
{
	long	sol;
	int		min;
	char	*tmp;

	tmp = (char *)str;
	sol = 0;
	min = 1;
	if (*tmp == '-')
	{
		min = -1;
		tmp++;
	}
	if (*tmp < '0' || *tmp > '9')
		return (2147483648);
	while (*tmp >= '0' && *tmp <= '9')
	{
		sol = (sol * 10) + (min * (*tmp - '0'));
		tmp++;
	}
	return (sol);
}
