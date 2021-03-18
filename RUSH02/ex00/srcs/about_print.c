/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyolee <yong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:30:10 by jaeyolee          #+#    #+#             */
/*   Updated: 2021/03/14 12:25:17 by jaeyolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		g_is_first = 1;
int		g_flag = 0;

void	print_dic_base(char *sol)
{
	int	i;

	if (g_flag == 1)
		return ;
	i = 0;
	while (i < g_len)
	{
		if (str_cmp(sol, g_dict[i].nb) == 0)
		{
			if (!g_is_first)
				write(1, " ", 1);
			put_str(g_dict[i].name);
			g_is_first = 0;
			return ;
		}
		i++;
	}
	g_flag = 1;
	write(2, ERROR_MSG1, E1_MSG);
}

void	print_dic_value(char *sol)
{
	int	i;

	if (g_flag == 1)
		return ;
	i = 0;
	while (i < g_len)
	{
		if (str_cmp(sol, g_dict[i].nb) == 0)
		{
			if (!g_is_first)
				write(1, " ", 1);
			put_str(g_dict[i].name);
			g_is_first = 0;
			free(sol);
			return ;
		}
		i++;
	}
	free(sol);
	g_flag = 1;
	write(2, ERROR_MSG1, E1_MSG);
}

char	*itoa(int nbr)
{
	int		cnt;
	int		tmp;
	char	*result;

	cnt = 0;
	tmp = nbr;
	while (tmp)
	{
		cnt++;
		tmp /= 10;
	}
	result = (char *)malloc(sizeof(char) * (cnt + 1));
	tmp = cnt;
	while (nbr)
	{
		result[--tmp] = nbr % 10 + '0';
		nbr /= 10;
	}
	result[cnt] = '\0';
	return (result);
}

int		ft_atoi(char *str, int size)
{
	int	n;

	n = 0;
	while (size)
	{
		n *= 10;
		n += *str - '0';
		--size;
		++str;
	}
	return (n);
}
