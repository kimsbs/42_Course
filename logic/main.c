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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g_x = 0;
int g_y = 0;
int g_MAX = 0;
#define Big(x, y) ((x>y) ? (x) : (y))
#define Small(x, y) ((x>y) ? (y) : (x))

char **strt;

void print_str(char *str)
{
	while(*str)
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
	while(i < size)
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
	while(g_x < tmp)
	{
		g_y = dump;
		while(g_y < tmp2)
		{
			strt[g_x][g_y] = 'x';
			g_y++;
		}
		g_x++;
	}
}

int possible(int i, int x, int y)
{
	int tmp;
	int tmp2;
	int y_t;

	y_t = y;
	tmp = x + i;
	tmp2 = y + i;
	while(x < tmp)
	{
		y = y_t;
		while(y < tmp2)
		{
			if(strt[x][y] == '0')
				return (0);
			y++;
		}
		x++;
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
	//printf("%d %d %d\n", t_x, t_y, end);
	while(i < end)
	{
		if(possible(i, l_x, l_y))
		{
			if(g_MAX < i)
			{
				g_MAX = i;
				g_x = l_x;
				g_y = l_y;
			}
		}
		else
			break;
		i++;
	}
}

void moving(int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < x - g_MAX)
	{
		j = 0;
		while(j < y - g_MAX)
		{
			checker(x, y, i, j);
			j++;
		}
		i++;
	}
	fill();
	print_all(strt, 9);
}

int main()
{
	strt = (char **)malloc(sizeof(char *) * 9);
	for(int i = 0; i< 9; i++)
		strt[i] = (char *)malloc(sizeof(char) * 27);
	for(int i =0 ; i< 9; i++)
		for(int j=0;j <28; j++)
			strt[i][j] = '.';

	
	strt[1][5] = '0';
	
	strt[2][15] = '0';

	strt[4][5] = '0';
	strt[5][10] = '0';
	strt[7][7] = '0';
	strt[7][22] = '0';
	strt[8][3] = '0';
	strt[8][11] = '0';

	print_all(strt, 9);
	printf("\n");
	moving(9, 28);
}
