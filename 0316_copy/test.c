/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:49:20 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/16 23:37:53 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int **arr;

int min_num(int a, int b, int c)
{
	int min;
	if (a > b)
		min = b;
	else
		min = a;
	if (min > c)
		min = c;
	return (min);
}

void print_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void print_all(int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		print_str(g_matrix[i].data);
		i++;
	}
}

void fill(void)
{
	int x = g_x - g_MAX;
	int y = g_y - g_MAX;
	int tmp = g_y;
	
	while(x < g_x)
	{
		g_y = tmp;
		while(y < g_y)
		{
			g_matrix[g_x].data[g_y] = g_find[2];
			g_y--;
		}
		g_x--;
	}
}

void last(int x, int y, int i)
{
	i = -1;
	while(++i < y)
		if(g_matrix[0].data[i] == g_find[0])
		{
			g_matrix[0].data[i] = g_find[2];
			return ;
		}
	i = -1;
	while(++i < x)
		if(g_matrix[i].data[0] == g_find[0])
		{
			g_matrix[i].data[0] = g_find[2];
			return ;
		}
}

int adder(int x, int y)
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
	if (g_matrix[x].depth[y] > g_MAX)
	{
		g_MAX = g_matrix[x].depth[y];
		g_x = x;
		g_y = y;
	}
	return (0);
}

void solve(int x, int y, int i, int j)
{
	if (x == 1 && y == 1 && g_matrix[0].data[0] == g_find[0])
		g_matrix[0].data[0] = g_find[2];
	else
	{
		while (++i < x)
		{
			j = 0;
			while (++j < y)
			{
				if (g_matrix[i].depth[j] == 1)
				{
					adder(i, j);
				}
			}
		}
		if(g_MAX != 0)
			fill();
		else
			last(x, y, 0);
	}
	print_all(x);
}

void make_matrix(int line, int hor)
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

void init_matrix(int line, int hor, char *map)
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

void free_matrix(char *map, int line)
{
	int i;

	free(map);
	i = -1;
	while (++i < line)
	{
		free(g_matrix[i].data);
		free(g_matrix[i].depth);
	}
	free(g_matrix);
	free(g_find);
}

int main(int argc, char **argv)
{
	int i;
	if (argc < 2)
	{
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		char *map = read_map(argv[i]);
		int line_cnt = infocheck(map);
		int hor_cnt = boxcheck(map, line_cnt);
		if (line_cnt < 0 || hor_cnt < 0)
			continue;
		make_matrix(line_cnt, hor_cnt);
		init_matrix(line_cnt, hor_cnt, map);
		g_x = 0;
		g_y = 0;
		g_MAX = 0;
		solve(line_cnt, hor_cnt, 0, 0);
		write(1, "\n", 1);
		free_matrix(map, line_cnt);
	}
}
