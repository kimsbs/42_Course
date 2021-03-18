/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:14:02 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/10 19:14:14 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		possible(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else if ('0' <= c && c <= '9')
		return (2);
	else if (c == ' ' || c == '	' || c == '\n')
		return (3);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (3);
	else
		return (0);
}

int		make_int(char *nbr, int cnt)
{
	int len;
	int i;
	int tmp;
	int sol;
	int tmp2;

	len = 0;
	sol = 0;
	while (possible(nbr[len]) == 2)
		len++;
	i = -1;
	while (++i < len)
	{
		tmp2 = len - i;
		tmp = 1;
		if (cnt % 2 != 0)
			tmp = -1;
		tmp *= nbr[i] - '0';
		while (--tmp2)
			tmp *= 10;
		sol += tmp;
	}
	return (sol);
}

int		ft_atoi(char *nbr)
{
	int		cnt;
	int		check;

	cnt = 0;
	check = 0;
	while (*nbr)
	{
		if (possible(*nbr))
		{
			if (possible(*nbr) <= 2)
				check = 1;
			else if (check == 1 && possible(*nbr) == 3)
				return (0);
			if (*nbr == '-')
				cnt++;
			else if (possible(*nbr) == 2)
				return (make_int(nbr, cnt));
		}
		else
			break ;
		nbr++;
	}
	return (0);
}
