/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:24:44 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/17 14:36:14 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	last(int x, int y, int i)
{
	i = -1;
	while (++i < y)
		if (g_matrix[x].data[i] == g_find[0])
		{
			if (g_max < g_matrix[x].depth[i])
			{
				g_max = g_matrix[x].depth[i];
				g_x = x;
				g_y = i;
			}
		}
}

int		adder(int x, int y)
{
	int left;
	int up;
	int leup;
	int min;

	left = g_matrix[x].depth[y - 1];
	up = g_matrix[x - 1].depth[y];
	leup = g_matrix[x - 1].depth[y - 1];
	min = min_num(left, up, leup);
	g_matrix[x].depth[y] = min + 1;
	if (g_matrix[x].depth[y] > g_max)
	{
		g_max = g_matrix[x].depth[y];
		g_x = x;
		g_y = y;
	}
	return (0);
}

void	solve(int x, int y, int i, int j)
{
	if (x == 1 && y == 1 && g_matrix[0].data[0] == g_find[0])
		g_matrix[0].data[0] = g_find[2];
	else
	{
		last(i, y, 0);
		while (++i < x)
		{
			last(i, y, 0);
			j = 0;
			while (++j < y)
			{
				if (g_matrix[i].depth[j] == 1)
				{
					adder(i, j);
				}
			}
		}
		fill();
	}
	print_all(x);
}

void	make_matrix(int line, int hor)
{
	int i;

	i = -1;
	g_matrix = (t_matrix *)malloc(sizeof(t_matrix) * line);
	while (++i < line)
	{
		g_matrix[i].data = (char *)malloc(sizeof(char) * (hor + 1));
		g_matrix[i].depth = (int *)malloc(sizeof(int) * (hor + 1));
	}
}

void	init_matrix(int line, int hor, char *map)
{
	int i;
	int j;

	while (*map != '\n')
		map++;
	map++;
	i = -1;
	while (++i < line)
	{
		j = -1;
		while (++j < hor)
		{
			g_matrix[i].data[j] = *map;
			if (*map == g_find[0])
				g_matrix[i].depth[j] = 1;
			else
				g_matrix[i].depth[j] = 0;
			map++;
		}
		g_matrix[i].data[j] = 0;
		map++;
	}
}
