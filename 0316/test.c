/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:49:20 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/15 20:28:09 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "map.h"

int g_x = 0;
int g_y = 0;
int g_MAX = -1;
#define Big(x, y) ((x>y) ? (x) : (y))
#define Small(x, y) ((x>y) ? (y) : (x))

char **strt;

void print_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void print_all(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		print_str(str[i]);
		i++;
	}
}

void fill()
{
	int tmp;
	int tmp2;
	int dump;

	dump = g_y;
	tmp = g_x + g_MAX;
	tmp2 = g_y + g_MAX;
	while (g_x < tmp)
	{
		g_y = dump;
		while (g_y < tmp2)
		{
			strt[g_x][g_y] = g_find[2];
			g_y++;
		}
		g_x++;
	}
}

int possible(int i, int x, int y)
{
	int tmp;
	int tmp2;

	tmp = x + i - 1;
	tmp2 = y + i - 1;
	while (y <= tmp2)
	{
		if (strt[tmp][y] == g_find[1])
			return (0);
		y++;
	}
	y--;
	while (tmp >= x)
	{
		if (strt[tmp][y] == g_find[1])
			return (0);
		tmp--;
	}
	return (1);
}

void checker(int x, int y, int l_x, int l_y)
{
	int tmp;
	int tmp2;
	int i;
	int end;

	i = 0;
	tmp = x - l_x;
	tmp2 = y - l_y;
	end = Small(tmp, tmp2);	
	while (i <= end)
	{
		if (possible(i, l_x, l_y))
		{
			if (g_MAX < i)
			{
				g_MAX = i;
				g_x = l_x;
				g_y = l_y;
			}
		}
		else
			break ;
		i++;
	}
}

void moving(int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < x - g_MAX)
	{
		j = 0;
		while (j < y - g_MAX)
		{
			checker(x, y, i, j);
			j++;
		}
		i++;
	}
	fill();
	print_all(strt, x);
}

void make_strt(int line, int hor)
{
	int i;

	i = 0;
	strt = (char **)malloc(sizeof(char *) * line);
	while(i < line)
	{
		strt[i] = (char *)malloc(sizeof(char) * (hor + 1));
		i++;
	}
}

void init_strt(int line, int hor, char *map)
{
	int i;
	int j;
	while(*map != '\n')
		map++;
	map++;
	i = -1;
	j = 0;
	while(++i < line)
	{
		j = 0;
		while(*map != '\n' && *map)
		{
			strt[i][j++] = *map;
			map++;	
		}
		strt[i][j] = 0;
		map++;
	}
}

void free_strt(char *map, int line)
{
	int i;

	free(map);
	i = -1;
	while(++i < line)
		free(strt[i]);
	free(strt);
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
		if(line_cnt < 0 || hor_cnt < 0)
			continue ;
		make_strt(line_cnt, hor_cnt);
		init_strt(line_cnt, hor_cnt, map);
		g_x = 0;
		g_y = 0;
		g_MAX = 0;
		moving(line_cnt, hor_cnt);
		write(1, "\n", 1);
		free_strt(map, line_cnt);
	}
}
