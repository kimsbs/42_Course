/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:28:44 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/10 20:34:44 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int g_x;
int g_y;
int g_move;

int		is_same(char str, char *charset)
{
	int cnt;

	cnt = 0;
	while (charset[cnt])
	{
		if (charset[cnt] == str)
			return (1);
		cnt++;
	}
	return (0);
}

void	arr_fill(char *str, char *charset, int *arr)
{
	int i;
	int cnt;
	int a_cnt;

	a_cnt = 0;
	cnt = 0;
	i = -1;
	while (str[++i])
	{
		if (is_same(str[i], charset))
		{
			if (cnt != 0)
			{
				arr[a_cnt] = cnt;
				a_cnt++;
			}
			cnt = 0;
		}
		else
			cnt++;
	}
	arr[a_cnt] = cnt;
}

void	split(char *str, char *charset, char **sol)
{
	int cnt;

	g_move = -1;
	g_x = 0;
	g_y = 0;
	cnt = 0;
	while (str[++g_move])
	{
		if (is_same(str[g_move], charset))
		{
			if (cnt != 0)
			{
				sol[g_x][g_y] = '\0';
				g_x++;
				g_y = 0;
			}
			cnt = 0;
		}
		else
		{
			sol[g_x][g_y++] = str[g_move];
			cnt++;
		}
	}
	sol[g_x][g_y] = '\0';
}

int		counter(char *str, char *set)
{
	int cnt;
	int flag;

	flag = 0;
	cnt = 0;
	while (*str)
	{
		if (!is_same(*str, set) && flag == 0)
		{
			cnt++;
			flag = 1;
		}
		else if (is_same(*str, set))
			flag = 0;
		str++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		*arr;
	char	**sol;

	size = counter(str, charset);
	arr = (int *)malloc(sizeof(int) * (size + 1));
	sol = (char **)malloc(sizeof(char *) * (size + 1));
	arr_fill(str, charset, arr);
	g_move = -1;
	while (++g_move <= size)
		sol[g_move] = (char *)malloc(sizeof(char *) * (arr[g_move] + 1));
	split(str, charset, sol);
	sol[size] = 0;
	return (sol);
}
