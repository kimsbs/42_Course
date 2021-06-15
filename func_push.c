/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:11:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/15 16:44:11 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	push_a(t_list **a, t_list **b)
{
	int		tmp;

	if(!*b)
		return ;
	tmp = (*b)->index;
	rm_front(b);
	add_front(a, tmp);
	write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	int		tmp;

	if(!*a)
		return ;
	tmp = (*a)->index;
	rm_front(a);
	add_front(b, tmp);
	write(1, "pb\n", 3);
}

static int		is_space(const char c)
{
	if (c == '\t' || c == ' ' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	long	sol;
	int		min;
	char	*tmp;

	tmp = (char *)str;
	sol = 0;
	min = 1;
	while (is_space(*tmp))
		tmp++;
	if (*tmp == '+' || *tmp == '-')
	{
		if (*tmp == '-')
			min = -1;
		tmp++;
	}
	while (*tmp >= '0' && *tmp <= '9')
	{
		sol = (sol * 10) + (min * (*tmp - '0'));
		tmp++;
		if (sol > 2147483647)
			return (-1);
		if (sol < -2147483648)
			return (0);
	}
	return ((int)sol);
}
