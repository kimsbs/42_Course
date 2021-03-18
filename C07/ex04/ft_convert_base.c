/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:28:21 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/11 02:12:39 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int g_sol = 0;

char	*ft_convert_base2(int sol, char *base_to);

int		space_first(char *nbr, char *base_from);

int		base_check(char *base)
{
	int i;
	int j;

	g_sol = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == ' ' || base[i] == '\t' || base[i] == '\n'
				|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int		find_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		possible(char c, char *base)
{
	if (c == '+' || c == '-')
		return (1);
	else if (find_base(c, base) != -1)
		return (2);
	else if (c == ' ' || c == '	' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (3);
	else
		return (0);
}

int		make_int(char *nbr, int cnt, char *base, int b_len)
{
	int len;
	int i;
	int tmp;
	int sol;
	int tmp2;

	while (base[b_len])
		b_len++;
	len = 0;
	sol = 0;
	while (possible(nbr[len], base) == 2)
		len++;
	i = -1;
	while (++i < len)
	{
		tmp2 = len - i;
		tmp = 1;
		if (cnt % 2 != 0)
			tmp = -1;
		tmp *= find_base(nbr[i], base);
		while (--tmp2)
			tmp *= b_len;
		sol += tmp;
	}
	return (sol);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		cnt;
	char	*tmp;

	cnt = 0;
	if (!base_check(base_from) || !base_check(base_to))
		return (0);
	if (space_first(nbr, base_from))
		while (*nbr)
		{
			if (possible(*nbr, base_from))
			{
				if (*nbr == '-')
					cnt++;
				else if (find_base(*nbr, base_from) != -1)
				{
					g_sol = make_int(nbr, cnt, base_from, 0);
					break ;
				}
				nbr++;
			}
			else
				break ;
		}
	tmp = ft_convert_base2(g_sol, base_to);
	return (tmp);
}
