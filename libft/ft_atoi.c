/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:28:37 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/12 09:57:41 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
