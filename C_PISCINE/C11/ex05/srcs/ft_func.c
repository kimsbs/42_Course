/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:09:29 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/18 00:25:04 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		str_cmp(char *a, char *b)
{
	while (*a || *b)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (*a - *b);
}

int		str_len(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int init;
	int sol;

	sol = 0;
	init = 1;
	while (is_space(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			init *= -1;
		str++;
	}
	while (('0' <= *str && *str <= '9') && *str)
	{
		sol = sol * 10 + (*str - '0') * init;
		str++;
	}
	return (sol);
}

void	ft_itoa(int tmp)
{
	int		dump;
	char	c;

	if (tmp == 0)
		return ;
	ft_itoa(tmp / 10);
	dump = tmp % 10;
	if (dump < 0)
		dump *= -1;
	c = dump + '0';
	write(1, &c, 1);
}
