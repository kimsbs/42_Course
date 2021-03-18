/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:19:58 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/11 04:44:22 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int g_count;

int		base_check(char *base)
{
	int i;
	int j;

	g_count = 0;
	if (*base == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == ' ' || base[i] == '	' || base[i] == '\n'
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

int		possible(char c, char *base, int count)
{
	if (c == '+' || c == '-')
		return (1);
	else if (find_base(c, base) != -1)
		return (2);
	else if (c == ' ' || c == '	' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
	{
		if (count == 1)
			return (0);
		else
			return (1);
	}
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

	len = 0;
	sol = 0;
	while (possible(nbr[len], base, 0) == 2)
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

int		ft_atoi_base(char *str, char *base)
{
	int cnt;
	int b_len;

	cnt = 0;
	b_len = 0;
	if (!base_check(base))
		return (0);
	while (base[b_len])
		b_len++;
	while (*str)
	{
		if (possible(*str, base, g_count))
		{
			if (possible(*str, base, g_count) <= 2)
				g_count = 1;
			if (*str == '-')
				cnt++;
			else if (find_base(*str, base) != -1)
				return (make_int(str, cnt, base, b_len));
			str++;
		}
		else
			break ;
	}
	return (0);
}
