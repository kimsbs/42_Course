/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:28:37 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/06 21:03:53 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_space(const char c)
{
	if (c == '\t' || c == ' ' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *str)
{
	int		sol;
	int		min;

	sol = 0;
	min = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sol = (sol * 10) + (min * (*str - '0'));
		str++;
	}
	return (sol);
}
